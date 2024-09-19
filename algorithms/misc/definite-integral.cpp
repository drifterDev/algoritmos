#include <bits/stdc++.h>
using namespace std;
const int steps=1000*1000; // %2==0

double f(double x){
	return 2*x*x-3*x+5;
}

double simpson_integration(double a, double b){
	double h=(b-a)/steps;
	double s=f(a)+f(b);
	for(int i=1;i<=steps-1;i++){ 
		double x=a+h*i;
		s+=f(x)*((i&1)?4:2);
	}
	s*=h/3;
	return s;
}