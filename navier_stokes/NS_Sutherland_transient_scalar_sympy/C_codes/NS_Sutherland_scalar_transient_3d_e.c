/****************************************************************************** 
 *                      Code generated with sympy 0.6.7                       * 
 *                                                                            * 
 *              See http://www.sympy.org/ for more information.               * 
 *                                                                            * 
 *                       This file is part of 'project'                       * 
 ******************************************************************************/

#include "NS_Sutherland_scalar_transient_3d_e.h"
#include <math.h>

double Rho(double L, double Lt, double a_rhot, double a_rhox, double a_rhoy, double a_rhoz, double rho_0, double rho_t, double rho_x, double rho_y, double rho_z, double t, double x, double y, double z) {
  return rho_0 + rho_t*sin(M_PI*a_rhot*t/Lt) + rho_x*sin(M_PI*a_rhox*x/L) + rho_y*cos(M_PI*a_rhoy*y/L) + rho_z*sin(M_PI*a_rhoz*z/L);
}

double U(double L, double Lt, double a_ut, double a_ux, double a_uy, double a_uz, double t, double u_0, double u_t, double u_x, double u_y, double u_z, double x, double y, double z) {
  return u_0 + u_t*cos(M_PI*a_ut*t/Lt) + u_x*sin(M_PI*a_ux*x/L) + u_y*cos(M_PI*a_uy*y/L) + u_z*cos(M_PI*a_uz*z/L);
}

double V(double L, double Lt, double a_vt, double a_vx, double a_vy, double a_vz, double t, double v_0, double v_t, double v_x, double v_y, double v_z, double x, double y, double z) {
  return v_0 + v_t*sin(M_PI*a_vt*t/Lt) + v_x*cos(M_PI*a_vx*x/L) + v_y*sin(M_PI*a_vy*y/L) + v_z*sin(M_PI*a_vz*z/L);
}

double W(double L, double Lt, double a_wt, double a_wx, double a_wy, double a_wz, double t, double w_0, double w_t, double w_x, double w_y, double w_z, double x, double y, double z) {
  return w_0 + w_t*cos(M_PI*a_wt*t/Lt) + w_x*sin(M_PI*a_wx*x/L) + w_y*sin(M_PI*a_wy*y/L) + w_z*cos(M_PI*a_wz*z/L);
}

double P(double L, double Lt, double a_pt, double a_px, double a_py, double a_pz, double p_0, double p_t, double p_x, double p_y, double p_z, double t, double x, double y, double z) {
  return p_0 + p_t*cos(M_PI*a_pt*t/Lt) + p_x*cos(M_PI*a_px*x/L) + p_y*sin(M_PI*a_py*y/L) + p_z*cos(M_PI*a_pz*z/L);
}

double T(double P, double R, double Rho) {
  return P/(R*Rho);
}

double E_t(double P, double Rho, double U, double V, double W, double gamma) {
  return -P/(Rho*(1 - gamma)) + pow(U,2)/2 + pow(V,2)/2 + pow(W,2)/2;
}

double A_mu(double B_mu, double T_ref, double mu_ref) {
  return mu_ref*pow(T_ref,-1.5)*(B_mu + T_ref);
}

double Mu(double A_mu, double B_mu, double T) {
  return A_mu*pow(T,1.5)/(B_mu + T);
}

double DMu_Dx(double A_mu, double B_mu, double L, double R, double Rho, double T, double a_px, double a_rhox, double p_x, double rho_x, double x) {
  return A_mu*pow(T,0.5)*(-1.5*M_PI*T*a_rhox*rho_x*cos(M_PI*a_rhox*x/L)/(L*Rho) - 1.5*M_PI*a_px*p_x*sin(M_PI*a_px*x/L)/(L*R*Rho))/(B_mu + T) + A_mu*pow(T,1.5)*(M_PI*T*a_rhox*rho_x*cos(M_PI*a_rhox*x/L)/(L*Rho) + M_PI*a_px*p_x*sin(M_PI*a_px*x/L)/(L*R*Rho))/pow((B_mu + T),2);
}

double DMu_Dy(double A_mu, double B_mu, double L, double R, double Rho, double T, double a_py, double a_rhoy, double p_y, double rho_y, double y) {
  return A_mu*pow(T,0.5)*(1.5*M_PI*T*a_rhoy*rho_y*sin(M_PI*a_rhoy*y/L)/(L*Rho) + 1.5*M_PI*a_py*p_y*cos(M_PI*a_py*y/L)/(L*R*Rho))/(B_mu + T) + A_mu*pow(T,1.5)*(-M_PI*T*a_rhoy*rho_y*sin(M_PI*a_rhoy*y/L)/(L*Rho) - M_PI*a_py*p_y*cos(M_PI*a_py*y/L)/(L*R*Rho))/pow((B_mu + T),2);
}

double DMu_Dz(double A_mu, double B_mu, double L, double R, double Rho, double T, double a_pz, double a_rhoz, double p_z, double rho_z, double z) {
  return A_mu*pow(T,0.5)*(-1.5*M_PI*T*a_rhoz*rho_z*cos(M_PI*a_rhoz*z/L)/(L*Rho) - 1.5*M_PI*a_pz*p_z*sin(M_PI*a_pz*z/L)/(L*R*Rho))/(B_mu + T) + A_mu*pow(T,1.5)*(M_PI*T*a_rhoz*rho_z*cos(M_PI*a_rhoz*z/L)/(L*Rho) + M_PI*a_pz*p_z*sin(M_PI*a_pz*z/L)/(L*R*Rho))/pow((B_mu + T),2);
}

double Q_et_convection(double E_t, double L, double P, double Rho, double U, double V, double W, double a_px, double a_py, double a_pz, double a_rhox, double a_rhoy, double a_rhoz, double a_ux, double a_uy, double a_uz, double a_vx, double a_vy, double a_vz, double a_wx, double a_wy, double a_wz, double gamma, double p_x, double p_y, double p_z, double rho_x, double rho_y, double rho_z, double u_x, double u_y, double u_z, double v_x, double v_y, double v_z, double w_x, double w_y, double w_z, double x, double y, double z) {
  return M_PI*Rho*(a_ux*u_x*pow(U,2)*cos(M_PI*a_ux*x/L) + a_vy*v_y*pow(V,2)*cos(M_PI*a_vy*y/L) - a_wz*w_z*pow(W,2)*sin(M_PI*a_wz*z/L) + U*W*a_wx*w_x*cos(M_PI*a_wx*x/L) + V*W*a_vz*v_z*cos(M_PI*a_vz*z/L) + V*W*a_wy*w_y*cos(M_PI*a_wy*y/L) - U*V*a_uy*u_y*sin(M_PI*a_uy*y/L) - U*V*a_vx*v_x*sin(M_PI*a_vx*x/L) - U*W*a_uz*u_z*sin(M_PI*a_uz*z/L))/L + M_PI*(U*a_px*p_x*sin(M_PI*a_px*x/L) + W*a_pz*p_z*sin(M_PI*a_pz*z/L) - V*a_py*p_y*cos(M_PI*a_py*y/L))/(L*(1 - gamma)) + M_PI*E_t*Rho*(a_ux*u_x*cos(M_PI*a_ux*x/L) + a_vy*v_y*cos(M_PI*a_vy*y/L) - a_wz*w_z*sin(M_PI*a_wz*z/L))/L + M_PI*a_rhox*rho_x*(E_t*U + P*U/(Rho*(1 - gamma)))*cos(M_PI*a_rhox*x/L)/L + M_PI*a_rhoy*rho_y*(-E_t*V - P*V/(Rho*(1 - gamma)))*sin(M_PI*a_rhoy*y/L)/L + M_PI*a_rhoz*rho_z*(E_t*W + P*W/(Rho*(1 - gamma)))*cos(M_PI*a_rhoz*z/L)/L;
}

double Q_et_gradp(double L, double P, double U, double V, double W, double a_px, double a_py, double a_pz, double a_ux, double a_vy, double a_wz, double p_x, double p_y, double p_z, double u_x, double v_y, double w_z, double x, double y, double z) {
  return M_PI*P*(a_ux*u_x*cos(M_PI*a_ux*x/L) + a_vy*v_y*cos(M_PI*a_vy*y/L) - a_wz*w_z*sin(M_PI*a_wz*z/L))/L + M_PI*V*a_py*p_y*cos(M_PI*a_py*y/L)/L - M_PI*U*a_px*p_x*sin(M_PI*a_px*x/L)/L - M_PI*W*a_pz*p_z*sin(M_PI*a_pz*z/L)/L;
}

double Q_et_viscous(double DMu_Dx, double DMu_Dy, double DMu_Dz, double L, double Mu, double U, double V, double W, double a_ux, double a_uy, double a_uz, double a_vx, double a_vy, double a_vz, double a_wx, double a_wy, double a_wz, double u_x, double u_y, double u_z, double v_x, double v_y, double v_z, double w_x, double w_y, double w_z, double x, double y, double z) {
  return Mu*pow(M_PI,2)*(U*(u_y*pow(a_uy,2)*cos(M_PI*a_uy*y/L) + u_z*pow(a_uz,2)*cos(M_PI*a_uz*z/L) + 4*u_x*pow(a_ux,2)*sin(M_PI*a_ux*x/L)/3) + V*(v_x*pow(a_vx,2)*cos(M_PI*a_vx*x/L) + v_z*pow(a_vz,2)*sin(M_PI*a_vz*z/L) + 4*v_y*pow(a_vy,2)*sin(M_PI*a_vy*y/L)/3) + W*(w_x*pow(a_wx,2)*sin(M_PI*a_wx*x/L) + w_y*pow(a_wy,2)*sin(M_PI*a_wy*y/L) + 4*w_z*pow(a_wz,2)*cos(M_PI*a_wz*z/L)/3) - 2*a_uy*a_vx*u_y*v_x*sin(M_PI*a_uy*y/L)*sin(M_PI*a_vx*x/L) - 2*a_vz*a_wy*v_z*w_y*cos(M_PI*a_vz*z/L)*cos(M_PI*a_wy*y/L) + 2*a_uz*a_wx*u_z*w_x*cos(M_PI*a_wx*x/L)*sin(M_PI*a_uz*z/L) - 4*a_ux*a_wz*u_x*w_z*cos(M_PI*a_ux*x/L)*sin(M_PI*a_wz*z/L)/3 - 4*a_vy*a_wz*v_y*w_z*cos(M_PI*a_vy*y/L)*sin(M_PI*a_wz*z/L)/3 + 4*a_ux*a_vy*u_x*v_y*cos(M_PI*a_ux*x/L)*cos(M_PI*a_vy*y/L)/3 - pow(a_uy,2)*pow(u_y,2)*pow(sin(M_PI*a_uy*y/L),2) - pow(a_uz,2)*pow(u_z,2)*pow(sin(M_PI*a_uz*z/L),2) - pow(a_vx,2)*pow(v_x,2)*pow(sin(M_PI*a_vx*x/L),2) - pow(a_vz,2)*pow(v_z,2)*pow(cos(M_PI*a_vz*z/L),2) - pow(a_wx,2)*pow(w_x,2)*pow(cos(M_PI*a_wx*x/L),2) - pow(a_wy,2)*pow(w_y,2)*pow(cos(M_PI*a_wy*y/L),2) - 4*pow(a_ux,2)*pow(u_x,2)*pow(cos(M_PI*a_ux*x/L),2)/3 - 4*pow(a_vy,2)*pow(v_y,2)*pow(cos(M_PI*a_vy*y/L),2)/3 - 4*pow(a_wz,2)*pow(w_z,2)*pow(sin(M_PI*a_wz*z/L),2)/3)/pow(L,2) + M_PI*DMu_Dx*U*(-4*a_ux*u_x*cos(M_PI*a_ux*x/L)/3 - 2*a_wz*w_z*sin(M_PI*a_wz*z/L)/3 + 2*a_vy*v_y*cos(M_PI*a_vy*y/L)/3)/L + M_PI*DMu_Dx*V*(a_uy*u_y*sin(M_PI*a_uy*y/L) + a_vx*v_x*sin(M_PI*a_vx*x/L))/L + M_PI*DMu_Dx*W*(a_uz*u_z*sin(M_PI*a_uz*z/L) - a_wx*w_x*cos(M_PI*a_wx*x/L))/L + M_PI*DMu_Dy*U*(a_uy*u_y*sin(M_PI*a_uy*y/L) + a_vx*v_x*sin(M_PI*a_vx*x/L))/L + M_PI*DMu_Dy*V*(-4*a_vy*v_y*cos(M_PI*a_vy*y/L)/3 - 2*a_wz*w_z*sin(M_PI*a_wz*z/L)/3 + 2*a_ux*u_x*cos(M_PI*a_ux*x/L)/3)/L + M_PI*DMu_Dy*W*(-a_vz*v_z*cos(M_PI*a_vz*z/L) - a_wy*w_y*cos(M_PI*a_wy*y/L))/L + M_PI*DMu_Dz*U*(a_uz*u_z*sin(M_PI*a_uz*z/L) - a_wx*w_x*cos(M_PI*a_wx*x/L))/L + M_PI*DMu_Dz*V*(-a_vz*v_z*cos(M_PI*a_vz*z/L) - a_wy*w_y*cos(M_PI*a_wy*y/L))/L + M_PI*DMu_Dz*W*(2*a_ux*u_x*cos(M_PI*a_ux*x/L)/3 + 2*a_vy*v_y*cos(M_PI*a_vy*y/L)/3 + 4*a_wz*w_z*sin(M_PI*a_wz*z/L)/3)/L;
}

double Q_et_heatflux(double L, double P, double R, double Rho, double a_px, double a_py, double a_pz, double a_rhox, double a_rhoy, double a_rhoz, double k, double p_x, double p_y, double p_z, double rho_x, double rho_y, double rho_z, double x, double y, double z) {
  return k*pow(M_PI,2)*(p_x*pow(a_px,2)*cos(M_PI*a_px*x/L) + p_y*pow(a_py,2)*sin(M_PI*a_py*y/L) + p_z*pow(a_pz,2)*cos(M_PI*a_pz*z/L))/(pow(L,2)*R*Rho) + k*pow(M_PI,2)*(-2*a_px*a_rhox*p_x*rho_x*cos(M_PI*a_rhox*x/L)*sin(M_PI*a_px*x/L) - 2*a_py*a_rhoy*p_y*rho_y*cos(M_PI*a_py*y/L)*sin(M_PI*a_rhoy*y/L) - 2*a_pz*a_rhoz*p_z*rho_z*cos(M_PI*a_rhoz*z/L)*sin(M_PI*a_pz*z/L))/(pow(L,2)*R*pow(Rho,2)) + P*k*pow(M_PI,2)*(-2*pow(a_rhox,2)*pow(rho_x,2)*pow(cos(M_PI*a_rhox*x/L),2) - 2*pow(a_rhoy,2)*pow(rho_y,2)*pow(sin(M_PI*a_rhoy*y/L),2) - 2*pow(a_rhoz,2)*pow(rho_z,2)*pow(cos(M_PI*a_rhoz*z/L),2))/(pow(L,2)*R*pow(Rho,3)) + P*k*pow(M_PI,2)*(-rho_x*pow(a_rhox,2)*sin(M_PI*a_rhox*x/L) - rho_y*pow(a_rhoy,2)*cos(M_PI*a_rhoy*y/L) - rho_z*pow(a_rhoz,2)*sin(M_PI*a_rhoz*z/L))/(pow(L,2)*R*pow(Rho,2));
}

double Q_et_time(double E_t, double Lt, double P, double Rho, double U, double V, double W, double a_pt, double a_rhot, double a_ut, double a_vt, double a_wt, double gamma, double p_t, double rho_t, double t, double u_t, double v_t, double w_t) {
  return M_PI*Rho*(V*a_vt*v_t*cos(M_PI*a_vt*t/Lt) - U*a_ut*u_t*sin(M_PI*a_ut*t/Lt) - W*a_wt*w_t*sin(M_PI*a_wt*t/Lt))/Lt + M_PI*E_t*a_rhot*rho_t*cos(M_PI*a_rhot*t/Lt)/Lt + M_PI*a_pt*p_t*sin(M_PI*a_pt*t/Lt)/(Lt*(1 - gamma)) + M_PI*P*a_rhot*rho_t*cos(M_PI*a_rhot*t/Lt)/(Lt*Rho*(1 - gamma));
}

double Q_et(double Q_et_convection, double Q_et_gradp, double Q_et_heatflux, double Q_et_time, double Q_et_viscous) {
  return Q_et_convection + Q_et_gradp + Q_et_heatflux + Q_et_time + Q_et_viscous;
}


