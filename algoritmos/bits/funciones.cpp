// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

// Revisa si un bit esta prendido
bool is_set(unsigned int number, int x){
  return (number >> x) & 1;
}

// Revisa si el número es potencia de 2
bool isPowerOfTwo(unsigned int n){
  return n && !(n & (n - 1));
}

// Cuenta el número de bits prendidos
int countSetBits(int n){
  int count = 0;
  while (n){
    n = n & (n - 1);
    count++;
  }return count;
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
cout << is_set(16, 4) << "\n";
cout << isPowerOfTwo(15) << "\n";
cout << countSetBits(16) << "\n";
return 0;
}