// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;

double f(double x){
	return x*x;
}

// O(log((r-l)/eps))
double ternary_search(double l, double r) {
	while(r-l>EPS) {
		double m1=l+(r-l)/3;
		double m2=r-(r-l)/3;
		if (f(m1)<f(m2))l=m1;
		else r=m2;
	}return max(f(l),f(r)); 
}
