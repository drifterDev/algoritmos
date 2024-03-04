// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
// number of steps (already multiplied by 2)
const int N=1000*1000; 

double f(double x){
  return 2*x*x-3*x+5;
}

double simpson_integration(double a, double b){
  double h=(b-a)/N;
  double s=f(a)+f(b);
  for(int i=1;i<=N-1;i++){ 
    double x=a+h*i;
    s+=f(x)*((i & 1)?4:2);
  }
  s*=h/3;
  return s;
}