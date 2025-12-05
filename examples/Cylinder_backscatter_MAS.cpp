#include <bits/stdc++.h>
#include <matrix.hpp>
using namespace dense;
double pi = 3.141592653589793;
std::complex<double> hankel2(int order, double x){
    std::complex<double> j{0, 1};
    std::complex<double> ret = std::cyl_bessel_j(order, x) -(std::cyl_neumann(order, x))*j;
    return ret;
}

std::complex<double> E_aux(double xs, double ys, double x, double y){
    double d = std::sqrt((xs-x)*(xs-x)+(ys-y)*(ys-y));
    double k = 2*pi;
    return hankel2(0, d*k);
}

std::complex<double> E_i(double x, double y){
    double k = 2*pi;
    std::complex<double> jay(0,1);
    return std::exp(jay*k*x);
}

std::complex<double> aux_adder(int order, std::vector<std::complex<double>> coefficients, double x, double y, std::vector<double> sourcesx, std::vector<double> sourcesy){
    std::complex<double> f(0,0);
    for (int i = 0; i<order; i++){
        f += coefficients[i]*E_aux(sourcesx[i], sourcesy[i], x, y);
    }
    return f;
}

double s2d_a(double phi, double r1){
    std::complex<double> s(0,0);
    for(int i=0; i<150; i++){
        if (i == 0){
            s += (std::cyl_bessel_j(i,2*pi*r1)/hankel2(i,2*pi*r1))*std::cos(i*phi);
        }
        else{
            s += 2.0*(std::cyl_bessel_j(i,2*pi*r1)/hankel2(i,2*pi*r1))*std::cos(i*phi);
        }
    }
    return (2/pi)*((std::abs(s))*(std::abs(s)));
}

int main(){
double r1 = 0.6; // cylinder radius in wavelengths
double r2 = 0.3; // auxiliary surface radius
int n = 50; // # of auxiliary sources
double c = 3E8;

double separation_angle = pi * 2 / n;
std::vector<double> aux_sources_x(n,0);
std::vector<double> aux_sources_y(n,0);
for(int i = 0; i<n; i++){
    aux_sources_x[i] = r2*std::cos(i*separation_angle);
    aux_sources_y[i] = r2*std::sin(i*separation_angle);
}
std::vector<double> controls_x(n,0);
std::vector<double> controls_y(n,0);
for(int i = 0; i<n; i++){
    controls_x[i] = r1*std::cos(i*separation_angle);
    controls_y[i] = r1*std::sin(i*separation_angle);
}

std::vector<std::complex<double>> control_points_inc(n,0);
for(int i = 0; i<n; i++){
    control_points_inc[i] = -E_i(controls_x[i], controls_y[i]);
}

matrix<std::complex<double>> A(n,n);
for (int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
        std::complex<double> w = E_aux(aux_sources_x[j], aux_sources_y[j], controls_x[i], controls_y[i]);
        A.set_value_at(i*n+j, w);
    }
}
std::vector<std::complex<double>> a = LU_solver(A, control_points_inc);

// Testing for convergence on the boundary.
std::vector<double> residual;
for (double i =0; i<2*pi; i+=(2*pi)/(n*10)){
    std::complex<double> total_field = E_i(r1 * std::cos(i), r1 * std::sin(i)) + aux_adder(n, a,r1 * std::cos(i), r1 * std::sin(i), aux_sources_x, aux_sources_y);
    residual.push_back(std::abs(total_field.real()));
}

double max = *std::max_element(residual.begin(), residual.end());
std::cout << "Max abs residual: " << max << std::endl;
}

