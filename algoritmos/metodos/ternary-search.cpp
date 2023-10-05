// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

double f(double x){
  return x*x;
}

// O(log((r-l)/eps))
double ternary_search(double l, double r) {
  double eps=1e-9; // precision
  while(r-l>eps) {
    double m1=l+(r-l)/3;
    double m2=r-(r-l)/3;
    if (f(m1)<f(m2))l=m1;
    else r=m2;
  }return max(f(l),f(r)); // El maximo de la funcion en el intervalo [l,r]
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);

// Caso 1: Encontrar el máximo en el intervalo [-10, 10]
double result1 = ternary_search(-10, 10);
cout<<"Máximo en el intervalo [-10, 10]: "<<result1<<"\n";

// Caso 2: Encontrar el máximo en el intervalo [-5, 5]
double result2 = ternary_search(-5, 5);
cout<<"Máximo en el intervalo [-5, 5]: "<<result2<<"\n";

// Caso 3: Encontrar el máximo en el intervalo [0, 15]
double result3 = ternary_search(0, 15);
cout<<"Máximo en el intervalo [0, 15]: "<<result3<<"\n";

return 0;
}