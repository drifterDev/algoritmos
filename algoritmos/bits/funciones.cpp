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
  cout<<is_set(16, 4)<<"\n";
  cout<<isPowerOfTwo(15)<<"\n";
  cout<<countSetBits(16)<<"\n\n";

  // Usar solo con int
  int x = 5328; // 00000000000000000001010011010000
  cout<<__builtin_clz(x)<<"\n"; // 19 (numero de ceros a la izquierda)
  cout<<__builtin_ctz(x)<<"\n"; // 4 (numero de ceros a la derecha)
  cout<<__builtin_popcount(x)<<"\n"; // 5 (numero de bits prendidos)
  cout<<__builtin_parity(x)<<"\n"; // 1 (paridad, 1 si numero de bits prendidos es impar)
  return 0;
}