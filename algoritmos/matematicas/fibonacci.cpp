// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define S second
#define F first
typedef pair<int, int> ii;

// O(Log(n))
ii fib(int n){
    if(n==0) return {0, 1};
    auto p=fib(n>>1);
    int c=p.F*(2*p.S-p.F);
    int d=p.F*p.F+p.S*p.S;
    if (n&1)return {d, c + d};
    else return {c, d};
}
