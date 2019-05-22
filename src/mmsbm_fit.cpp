#include "MMModelClass.hpp"

using Rcpp::NumericMatrix;
using Rcpp::NumericVector;
using Rcpp::IntegerMatrix;
using Rcpp::IntegerVector;
using Rcpp::List;
using Rcpp::checkUserInterrupt;
using Rcpp::as;


// [[Rcpp::export]]
List mmsbm_fit(const NumericMatrix& z_t,
               const NumericMatrix& x_t,
               const NumericVector& y,
               const IntegerVector& time_id_dyad,
               const IntegerVector& time_id_node,
               const IntegerVector& nodes_per_period,
               const IntegerMatrix& node_id_dyad,
               const NumericMatrix& mu_b,
               const NumericMatrix& var_b,
               const NumericMatrix& phi_init,
                NumericMatrix& kappa_init_t,
                NumericMatrix& b_init_t,
                NumericVector& beta_init,
                NumericVector& gamma_init,
               List control
)
{
  //Obtain nr. of cores
  int N_THREADS = 1;
 #ifdef _OPENMP
   omp_set_num_threads(as<int>(control["threads"]));
   N_THREADS = as<int>(control["threads"]);
#endif
  
  
  //Create model instance
  MMModel Model(z_t,
                x_t,
                y,
                N_THREADS,
                time_id_dyad,
                time_id_node,
                nodes_per_period,
                node_id_dyad,
                mu_b,
                var_b,
                phi_init,
                kappa_init_t,
                b_init_t,
                beta_init,
                gamma_init,
                control
  );
  
  // VARIATIONAL EM
  int iter = 0,
    EM_ITER = as<int>(control["em_iter"]),
    N_BLK = as<int>(control["blocks"]),
    N_DYAD_PRED = z_t.nrow(),
    N_MONAD_PRED = x_t.nrow(),
    N_STATE = as<int>(control["states"]);
  
  //int TOT_BETA = N_MONAD_PRED * N_BLK * N_STATE,
  //  TOT_B = N_BLK * N_BLK;
  
  bool conv = false,
    verbose = as<bool>(control["verbose"]);

  double newLL, oldLL,
  tol = as<double>(control["conv_tol"]);
  
  // NumericVector Old_B(TOT_B),
  // Old_Gamma(N_DYAD_PRED),
  // Old_Beta(TOT_BETA);
  
  oldLL = Model.cLL();
  while(iter < EM_ITER && conv == false){
    checkUserInterrupt();
    
    // E-STEP
    Model.updatePhi();
    
    
    if(N_STATE > 1){
      Model.updateKappa();
    }

    
    
    //M-STEP
    // Model.getB(Old_B);
    // Model.getGamma(Old_Gamma);
    // Model.getBeta(Old_Beta);
//#pragma omp parallel sections
// {
// #pragma omp section
// {
Model.optim_ours(true); //optimize alphaLB
// }
// #pragma omp section
// {
 Model.optim_ours(false); //optimize thetaLB
// }
//  } 

  
    
    //Check convergence
    newLL = Model.cLL();
    
    if(fabs((newLL-oldLL)/oldLL) < tol){
      conv = true;
    } else {
      oldLL = newLL;
    }
    if(verbose)
      if((iter+1) % 25 == 0)
        Rprintf("LB %i: %f\n", iter + 1, newLL);
    
    ++iter;
  }
  if((conv == false) & verbose)
    Rprintf("\tWarning: model did not converge after %i iterations.\n", iter);
  
  
  
  //Form return objects
  NumericMatrix phi_res = Model.getC();
  NumericMatrix A = Model.getWmn();
  NumericMatrix kappa_res = Model.getKappa();
  NumericMatrix B = Model.getB();
  NumericVector gamma_res = Model.getGamma();
  List beta_res = Model.getBeta();
  
  
  List res;
  res["MixedMembership"] = phi_res;
  res["BlockModel"] = B;
  res["DyadCoef"] = gamma_res;
  res["TransitionKernel"] = A;
  res["MonadCoef"] = beta_res;
  res["Kappa"] = kappa_res;
  res["n_states"] = N_STATE;
  res["n_blocks"] = N_BLK;
  res["LowerBound"] = newLL;
  res["niter"] = iter;
  
  
  return res;
}
