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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // Casos de prueba para g(n)
  cout<<"Pruebas para g(n):\n";
  for (int n=0;n<10;n++)cout<<"g("<<n<<") = "<<g(n)<<"\n";

  // Casos de prueba para rev_g(g)
  cout<<"\nPruebas para rev_g(g):\n";
  for(int i=0;i<10;i++)cout<<"rev_g("<<i<<") = "<<rev_g(i)<<"\n";
  return 0;
}
