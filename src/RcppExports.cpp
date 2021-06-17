// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// approxB
Rcpp::NumericMatrix approxB(Rcpp::NumericVector y, Rcpp::IntegerMatrix d_id, Rcpp::NumericMatrix pi1_mat, Rcpp::Nullable<Rcpp::NumericMatrix> pi2_mat_tmp, bool directed);
RcppExport SEXP _NetMix_approxB(SEXP ySEXP, SEXP d_idSEXP, SEXP pi1_matSEXP, SEXP pi2_mat_tmpSEXP, SEXP directedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type y(ySEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerMatrix >::type d_id(d_idSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericMatrix >::type pi1_mat(pi1_matSEXP);
    Rcpp::traits::input_parameter< Rcpp::Nullable<Rcpp::NumericMatrix> >::type pi2_mat_tmp(pi2_mat_tmpSEXP);
    Rcpp::traits::input_parameter< bool >::type directed(directedSEXP);
    rcpp_result_gen = Rcpp::wrap(approxB(y, d_id, pi1_mat, pi2_mat_tmp, directed));
    return rcpp_result_gen;
END_RCPP
}
// getZ
Rcpp::IntegerMatrix getZ(Rcpp::NumericMatrix pi_mat);
RcppExport SEXP _NetMix_getZ(SEXP pi_matSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericMatrix >::type pi_mat(pi_matSEXP);
    rcpp_result_gen = Rcpp::wrap(getZ(pi_mat));
    return rcpp_result_gen;
END_RCPP
}
// vcovGamma_ext
arma::mat vcovGamma_ext(const arma::mat& X, const arma::vec& probs, const arma::vec& pen);
RcppExport SEXP _NetMix_vcovGamma_ext(SEXP XSEXP, SEXP probsSEXP, SEXP penSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type probs(probsSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type pen(penSEXP);
    rcpp_result_gen = Rcpp::wrap(vcovGamma_ext(X, probs, pen));
    return rcpp_result_gen;
END_RCPP
}
// vcovBeta_ext
arma::mat vcovBeta_ext(const arma::mat& X, const arma::mat& c_mat, const arma::mat& alpha, const arma::vec& alpha_sum, const arma::vec& kappa, const arma::vec& pen, const arma::vec& N, bool vcov);
RcppExport SEXP _NetMix_vcovBeta_ext(SEXP XSEXP, SEXP c_matSEXP, SEXP alphaSEXP, SEXP alpha_sumSEXP, SEXP kappaSEXP, SEXP penSEXP, SEXP NSEXP, SEXP vcovSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type c_mat(c_matSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type alpha_sum(alpha_sumSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type kappa(kappaSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type pen(penSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type N(NSEXP);
    Rcpp::traits::input_parameter< bool >::type vcov(vcovSEXP);
    rcpp_result_gen = Rcpp::wrap(vcovBeta_ext(X, c_mat, alpha, alpha_sum, kappa, pen, N, vcov));
    return rcpp_result_gen;
END_RCPP
}
// alphaLBound
Rcpp::NumericVector alphaLBound(arma::vec par, arma::vec tot_nodes, arma::mat c_t, arma::mat x_t, arma::umat s_mat, arma::uvec t_id, arma::cube var_beta, arma::cube mu_beta);
RcppExport SEXP _NetMix_alphaLBound(SEXP parSEXP, SEXP tot_nodesSEXP, SEXP c_tSEXP, SEXP x_tSEXP, SEXP s_matSEXP, SEXP t_idSEXP, SEXP var_betaSEXP, SEXP mu_betaSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type par(parSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type tot_nodes(tot_nodesSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type c_t(c_tSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type x_t(x_tSEXP);
    Rcpp::traits::input_parameter< arma::umat >::type s_mat(s_matSEXP);
    Rcpp::traits::input_parameter< arma::uvec >::type t_id(t_idSEXP);
    Rcpp::traits::input_parameter< arma::cube >::type var_beta(var_betaSEXP);
    Rcpp::traits::input_parameter< arma::cube >::type mu_beta(mu_betaSEXP);
    rcpp_result_gen = Rcpp::wrap(alphaLBound(par, tot_nodes, c_t, x_t, s_mat, t_id, var_beta, mu_beta));
    return rcpp_result_gen;
END_RCPP
}
// alphaGrad
arma::vec alphaGrad(arma::vec par, arma::uvec tot_nodes, arma::umat c_t, arma::mat x_t, arma::umat s_mat, arma::uvec t_id, arma::cube var_beta, arma::cube mu_beta);
RcppExport SEXP _NetMix_alphaGrad(SEXP parSEXP, SEXP tot_nodesSEXP, SEXP c_tSEXP, SEXP x_tSEXP, SEXP s_matSEXP, SEXP t_idSEXP, SEXP var_betaSEXP, SEXP mu_betaSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type par(parSEXP);
    Rcpp::traits::input_parameter< arma::uvec >::type tot_nodes(tot_nodesSEXP);
    Rcpp::traits::input_parameter< arma::umat >::type c_t(c_tSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type x_t(x_tSEXP);
    Rcpp::traits::input_parameter< arma::umat >::type s_mat(s_matSEXP);
    Rcpp::traits::input_parameter< arma::uvec >::type t_id(t_idSEXP);
    Rcpp::traits::input_parameter< arma::cube >::type var_beta(var_betaSEXP);
    Rcpp::traits::input_parameter< arma::cube >::type mu_beta(mu_betaSEXP);
    rcpp_result_gen = Rcpp::wrap(alphaGrad(par, tot_nodes, c_t, x_t, s_mat, t_id, var_beta, mu_beta));
    return rcpp_result_gen;
END_RCPP
}
// vertboot_matrix_rcpp2
Rcpp::List vertboot_matrix_rcpp2(Rcpp::IntegerMatrix m1, Rcpp::IntegerVector blist1, Rcpp::IntegerVector blist2);
RcppExport SEXP _NetMix_vertboot_matrix_rcpp2(SEXP m1SEXP, SEXP blist1SEXP, SEXP blist2SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::IntegerMatrix >::type m1(m1SEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerVector >::type blist1(blist1SEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerVector >::type blist2(blist2SEXP);
    rcpp_result_gen = Rcpp::wrap(vertboot_matrix_rcpp2(m1, blist1, blist2));
    return rcpp_result_gen;
END_RCPP
}
// mmsbm_fit
Rcpp::List mmsbm_fit(const arma::mat& z_t, const arma::mat& x_t, const arma::vec& y, const arma::uvec& time_id_dyad, const arma::uvec& time_id_node, const arma::uvec& nodes_per_period, const arma::umat& node_id_dyad, const arma::field<arma::uvec>& node_id_period, const arma::mat& mu_b, const arma::mat& var_b, const arma::cube& mu_beta, const arma::cube& var_beta, const arma::vec& mu_gamma, const arma::vec& var_gamma, const arma::mat& pi_init, arma::mat& kappa_init_t, arma::mat& b_init_t, arma::cube& beta_init_r, arma::vec& gamma_init_r, Rcpp::List& control);
RcppExport SEXP _NetMix_mmsbm_fit(SEXP z_tSEXP, SEXP x_tSEXP, SEXP ySEXP, SEXP time_id_dyadSEXP, SEXP time_id_nodeSEXP, SEXP nodes_per_periodSEXP, SEXP node_id_dyadSEXP, SEXP node_id_periodSEXP, SEXP mu_bSEXP, SEXP var_bSEXP, SEXP mu_betaSEXP, SEXP var_betaSEXP, SEXP mu_gammaSEXP, SEXP var_gammaSEXP, SEXP pi_initSEXP, SEXP kappa_init_tSEXP, SEXP b_init_tSEXP, SEXP beta_init_rSEXP, SEXP gamma_init_rSEXP, SEXP controlSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type z_t(z_tSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type x_t(x_tSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type y(ySEXP);
    Rcpp::traits::input_parameter< const arma::uvec& >::type time_id_dyad(time_id_dyadSEXP);
    Rcpp::traits::input_parameter< const arma::uvec& >::type time_id_node(time_id_nodeSEXP);
    Rcpp::traits::input_parameter< const arma::uvec& >::type nodes_per_period(nodes_per_periodSEXP);
    Rcpp::traits::input_parameter< const arma::umat& >::type node_id_dyad(node_id_dyadSEXP);
    Rcpp::traits::input_parameter< const arma::field<arma::uvec>& >::type node_id_period(node_id_periodSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type mu_b(mu_bSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type var_b(var_bSEXP);
    Rcpp::traits::input_parameter< const arma::cube& >::type mu_beta(mu_betaSEXP);
    Rcpp::traits::input_parameter< const arma::cube& >::type var_beta(var_betaSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type mu_gamma(mu_gammaSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type var_gamma(var_gammaSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type pi_init(pi_initSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type kappa_init_t(kappa_init_tSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type b_init_t(b_init_tSEXP);
    Rcpp::traits::input_parameter< arma::cube& >::type beta_init_r(beta_init_rSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type gamma_init_r(gamma_init_rSEXP);
    Rcpp::traits::input_parameter< Rcpp::List& >::type control(controlSEXP);
    rcpp_result_gen = Rcpp::wrap(mmsbm_fit(z_t, x_t, y, time_id_dyad, time_id_node, nodes_per_period, node_id_dyad, node_id_period, mu_b, var_b, mu_beta, var_beta, mu_gamma, var_gamma, pi_init, kappa_init_t, b_init_t, beta_init_r, gamma_init_r, control));
    return rcpp_result_gen;
END_RCPP
}
// mmsbm_fitBi
Rcpp::List mmsbm_fitBi(const arma::mat& z_t, const arma::mat& x1_t, const arma::mat& x2_t, const arma::vec& y, const arma::uvec& time_id_dyad, const arma::uvec& time_id_node1, const arma::uvec& time_id_node2, const arma::uvec& nodes_per_period, const arma::uvec& nodes_per_period1, const arma::uvec& nodes_per_period2, const arma::umat& node_id_dyad, const arma::field<arma::uvec>& node_id_period1, const arma::field<arma::uvec>& node_id_period2, const arma::mat& mu_b, const arma::mat& var_b, const arma::cube& mu_beta1, const arma::cube& var_beta1, const arma::cube& mu_beta2, const arma::cube& var_beta2, const arma::vec& mu_gamma, const arma::vec& var_gamma, const arma::mat& phi_init1, const arma::mat& phi_init2, arma::mat& kappa_init_t, arma::mat& b_init_t, arma::cube& beta1_init, arma::cube& beta2_init, arma::vec& gamma_init, Rcpp::List control);
RcppExport SEXP _NetMix_mmsbm_fitBi(SEXP z_tSEXP, SEXP x1_tSEXP, SEXP x2_tSEXP, SEXP ySEXP, SEXP time_id_dyadSEXP, SEXP time_id_node1SEXP, SEXP time_id_node2SEXP, SEXP nodes_per_periodSEXP, SEXP nodes_per_period1SEXP, SEXP nodes_per_period2SEXP, SEXP node_id_dyadSEXP, SEXP node_id_period1SEXP, SEXP node_id_period2SEXP, SEXP mu_bSEXP, SEXP var_bSEXP, SEXP mu_beta1SEXP, SEXP var_beta1SEXP, SEXP mu_beta2SEXP, SEXP var_beta2SEXP, SEXP mu_gammaSEXP, SEXP var_gammaSEXP, SEXP phi_init1SEXP, SEXP phi_init2SEXP, SEXP kappa_init_tSEXP, SEXP b_init_tSEXP, SEXP beta1_initSEXP, SEXP beta2_initSEXP, SEXP gamma_initSEXP, SEXP controlSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type z_t(z_tSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type x1_t(x1_tSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type x2_t(x2_tSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type y(ySEXP);
    Rcpp::traits::input_parameter< const arma::uvec& >::type time_id_dyad(time_id_dyadSEXP);
    Rcpp::traits::input_parameter< const arma::uvec& >::type time_id_node1(time_id_node1SEXP);
    Rcpp::traits::input_parameter< const arma::uvec& >::type time_id_node2(time_id_node2SEXP);
    Rcpp::traits::input_parameter< const arma::uvec& >::type nodes_per_period(nodes_per_periodSEXP);
    Rcpp::traits::input_parameter< const arma::uvec& >::type nodes_per_period1(nodes_per_period1SEXP);
    Rcpp::traits::input_parameter< const arma::uvec& >::type nodes_per_period2(nodes_per_period2SEXP);
    Rcpp::traits::input_parameter< const arma::umat& >::type node_id_dyad(node_id_dyadSEXP);
    Rcpp::traits::input_parameter< const arma::field<arma::uvec>& >::type node_id_period1(node_id_period1SEXP);
    Rcpp::traits::input_parameter< const arma::field<arma::uvec>& >::type node_id_period2(node_id_period2SEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type mu_b(mu_bSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type var_b(var_bSEXP);
    Rcpp::traits::input_parameter< const arma::cube& >::type mu_beta1(mu_beta1SEXP);
    Rcpp::traits::input_parameter< const arma::cube& >::type var_beta1(var_beta1SEXP);
    Rcpp::traits::input_parameter< const arma::cube& >::type mu_beta2(mu_beta2SEXP);
    Rcpp::traits::input_parameter< const arma::cube& >::type var_beta2(var_beta2SEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type mu_gamma(mu_gammaSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type var_gamma(var_gammaSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type phi_init1(phi_init1SEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type phi_init2(phi_init2SEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type kappa_init_t(kappa_init_tSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type b_init_t(b_init_tSEXP);
    Rcpp::traits::input_parameter< arma::cube& >::type beta1_init(beta1_initSEXP);
    Rcpp::traits::input_parameter< arma::cube& >::type beta2_init(beta2_initSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type gamma_init(gamma_initSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type control(controlSEXP);
    rcpp_result_gen = Rcpp::wrap(mmsbm_fitBi(z_t, x1_t, x2_t, y, time_id_dyad, time_id_node1, time_id_node2, nodes_per_period, nodes_per_period1, nodes_per_period2, node_id_dyad, node_id_period1, node_id_period2, mu_b, var_b, mu_beta1, var_beta1, mu_beta2, var_beta2, mu_gamma, var_gamma, phi_init1, phi_init2, kappa_init_t, b_init_t, beta1_init, beta2_init, gamma_init, control));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_NetMix_approxB", (DL_FUNC) &_NetMix_approxB, 5},
    {"_NetMix_getZ", (DL_FUNC) &_NetMix_getZ, 1},
    {"_NetMix_vcovGamma_ext", (DL_FUNC) &_NetMix_vcovGamma_ext, 3},
    {"_NetMix_vcovBeta_ext", (DL_FUNC) &_NetMix_vcovBeta_ext, 8},
    {"_NetMix_alphaLBound", (DL_FUNC) &_NetMix_alphaLBound, 8},
    {"_NetMix_alphaGrad", (DL_FUNC) &_NetMix_alphaGrad, 8},
    {"_NetMix_vertboot_matrix_rcpp2", (DL_FUNC) &_NetMix_vertboot_matrix_rcpp2, 3},
    {"_NetMix_mmsbm_fit", (DL_FUNC) &_NetMix_mmsbm_fit, 20},
    {"_NetMix_mmsbm_fitBi", (DL_FUNC) &_NetMix_mmsbm_fitBi, 29},
    {NULL, NULL, 0}
};

RcppExport void R_init_NetMix(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
