// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  stack<int> s;
  s.push(2); //[2]
  s.push(5); //[2,5]
  cout<<s.top()<<"\n"; //5
  s.pop(); //[2]
  cout<<s.top()<<"\n"; //2
  return 0;
}