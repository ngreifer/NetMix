#include "MMModelClassB.h"

// [[Rcpp::export(mmsbm_fit)]]
Rcpp::List mmsbm_fit(const arma::mat& z_t,
                     const arma::mat& x1_t,//for bipartite 2 X structures
                     const arma::mat& x2_t,
                     const arma::vec& y,
                     const arma::uvec& time_id_dyad,
                     const arma::uvec& time_id_node1,
                     const arma::uvec& time_id_node2,
                     const arma::uvec& nodes_per_period,//stacked, in the case of bipartite length N_TIME+N_TIME
                     const arma::uvec& nodes_per_period1,
                     const arma::uvec& nodes_per_period2,
                     const arma::umat& node_id_dyad,
                     const arma::field<arma::uvec>& node_id_period1,
                     const arma::field<arma::uvec>& node_id_period2,
                     const arma::mat& mu_b,
                     const arma::mat& var_b,
                     const arma::cube& mu_beta1,
                     const arma::cube& var_beta1,
                     const arma::cube& mu_beta2,
                     const arma::cube& var_beta2,
                     const arma::vec& mu_gamma,
                     const arma::vec& var_gamma,
                     const arma::mat& phi_init1,
                     const arma::mat& phi_init2,
                     arma::mat& kappa_init_t,
                     arma::mat& b_init_t,
                     arma::cube& beta1_init,
                     arma::cube& beta2_init,
                     arma::vec& gamma_init,
                     Rcpp::List control
)
{
  //Create model instance
Rprintf("Create model instance... \n");
  MMModelB ModelB(z_t,
                x1_t,
                x2_t,
                y,
                time_id_dyad,
                time_id_node1,
                time_id_node2,
                nodes_per_period,
                nodes_per_period1,
                nodes_per_period2,
                node_id_dyad,
                node_id_period1,
                node_id_period2,
                mu_b,
                var_b,
                mu_beta1,
                var_beta1,
                mu_beta2,
                var_beta2,
                mu_gamma,
                var_gamma,
                phi_init1,
                phi_init2,
                kappa_init_t,
                b_init_t,
                beta1_init,
                beta2_init,
                gamma_init,
                control
		);

  // VARIATIONAL EM
  arma::uword iter = 0, nworse = 0,
    win_size = control["conv_window"],//**
    VI_ITER = control["vi_iter"],
    BIPART = control["bipartite"],
    //N_NODE1 = sum(nodes_per_period1), N_NODE2 = sum(nodes_per_period2), 
    N_BLK1 = control["blocks1"],
    N_BLK2 = control["blocks2"],
    //N_DYAD_PRED = z_t.n_rows, N_MONAD_PRED1 = x1_t.n_rows, N_MONAD_PRED2 = control["npred2"],
    N_STATE = control["states"];
  
  bool conv = false,
    verbose = Rcpp::as<bool>(control["verbose"]),
    svi = Rcpp::as<bool>(control["svi"]);

  double tol = Rcpp::as<double>(control["conv_tol"]),
    newLL, oldLL;
  
  oldLL = -arma::datum::inf;
  newLL = 0.0;
  arma::vec running_ll(win_size, arma::fill::zeros);
  std::vector<double> ll_vec;
  
  while(iter < VI_ITER && conv == false){
    Rcpp::checkUserInterrupt();
    // E-STEP
    
    ModelB.updatePhi();
    
    if(N_STATE > 1){
          ModelB.updateKappa();
       }
    //
    //M-STEP
    // Sample batch of dyads for stochastic optim
    ModelB.sampleDyads(iter);
    ModelB.optim_ours(true);//optimize alphaLB 1,2
    ModelB.optim_ours(false);//optimize thetaLB
    //
    //Check convergence
    if(svi){
      newLL = ModelB.LB();
      std::rotate(running_ll.begin(), running_ll.begin() + 1, running_ll.end());
      running_ll[win_size - 1] = newLL;
      if(iter > win_size) {
        ModelB.convCheck(conv, running_ll, tol);
      }
    } else {
      newLL = ModelB.LB();
      //Rprintf("New %f, old %f\n", newLL, oldLL);
      conv = (fabs((newLL-oldLL)/oldLL) < tol);
    }
    ll_vec.push_back(newLL);
    oldLL = newLL;
    
    if(verbose){
      if((iter+1) % 1 == 0) {
        Rprintf("Iter: %i, LB: %f\r", iter + 1, newLL);
      }
    }
    ++iter;
  }
  if(verbose){
    Rprintf("Final LB: %f.                     \n", iter+1, newLL);
  }
  //Form return objects: 
  arma::mat C_res1 = ModelB.getC(false);//**
  arma::mat C_res2 = ModelB.getC(true);//**
  arma::mat postmm_res1 = ModelB.getPostMM1();//**
  arma::mat postmm_res2 = ModelB.getPostMM2();//**
  arma::mat send_phi = ModelB.getPhi(true);
  arma::mat rec_phi = ModelB.getPhi(false);
  arma::uvec tot_nodes1 = ModelB.getN(true);
  arma::uvec tot_nodes2 = ModelB.getN(false);
  arma::mat A = ModelB.getWmn(); 
  arma::mat kappa_res = ModelB.getKappa();
  arma::mat B = ModelB.getB();
  arma::vec gamma_res = ModelB.getGamma();
  arma::cube beta1_res = ModelB.getBeta1();
  arma::cube beta2_res = ModelB.getBeta2();
  
  Rcpp::List res;
  res["MixedMembership 1"] = postmm_res1; //** //phi_res1; 
  res["MixedMembership 2"] = postmm_res2; //**//phi_res2;
  res["CountMatrix1"] = C_res1;//**
  res["CountMatrix2"] = C_res2;//**
  res["SenderPhi"] = send_phi;
  res["ReceiverPhi"] = rec_phi;
  res["TotNodes1"] = tot_nodes1;
  res["TotNodes2"] = tot_nodes2;
  res["BlockModel"] = B;
  res["DyadCoef"] = gamma_res;
  res["TransitionKernel"] = A;
  res["MonadCoef1"] = beta1_res;
  res["MonadCoef2"] = beta2_res;
  res["Kappa"] = kappa_res;
  res["n_states"] = N_STATE;
  res["n_blocks1"] = N_BLK1;
  res["n_blocks2"] = N_BLK2;
  res["LowerBound"] = newLL;
  res["niter"] = iter + 1;
  res["converged"] = conv;
  res["LowerBound_full"] = Rcpp::wrap(ll_vec);//**
  
  return res;
}
