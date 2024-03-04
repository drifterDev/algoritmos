// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

// Gray code is a binary numeral system where two 
// successive values differ in only one bit.
// For example, the sequence of Gray codes for 
// 3-bit numbers is: 000, 001, 011, 010, 110, 111, 101, 100, so g(4)=6.
int g(int n){
  return n^(n>>1);
}

// The inverse of g(n)
int rev_g (int g) {
  int n=0;
  for(;g;g>>=1)
    n^=g;
  return n;
}

