// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

// Si x es ll usar en vez de 1<< usar 1ll<< 

// x & 1           -> Verifica si x es impar
// x & (1<<i)      -> Verifica si el i-esimo bit esta encendido
// x = x | (1<<i)  -> Enciende el i-esimo bit
// x = x & ~(1<<i) -> Apaga el i-esimo bit
// x = x ^ (1<<i)  -> Invierte el i-esimo bit
// x = ~x          -> Invierte todos los bits
// x & -x          -> Devuelve el bit encendido mas a la derecha (potencia de 2, no el indice)
// ~x & (x+1)      -> Devuelve el bit apagado mas a la derecha (potencia de 2, no el indice)
// x = x | (x+1)   -> Enciende el bit apagado mas a la derecha
// x = x & (x-1)   -> Apaga el bit encendido mas a la derecha
// x = x & ~y      -> Apaga en x los bits encendidos de y


// Revisa si un bit esta prendido
bool is_set(int number, int x){
  return number&(1<<x);
}

// Revisa si el número es potencia de 2
bool isPowerOfTwo(unsigned int n){
  return n && !(n&(n-1));
}

// Cuenta el número de bits prendidos
int countSetBits(int n){
  int count=0;
  while(n){
    n=n&(n-1);
    count++;
  }return count;
}

// Devuelve el bit menos significativo prendido
int lsb(int n){return n&(-n);}

int main() {
  cout<<is_set(16, 4)<<"\n";
  cout<<isPowerOfTwo(15)<<"\n";
  cout<<countSetBits(16)<<"\n";
  for(int i=0;i<16;++i){
    cout<<lsb(i)<<" "<<bitset<4>(i)<<"\n";
  }

  // Funciones de gcc. Si n es ll agregar el sufijo ll -> (__builtin_clzll(x)).
  int x = 5328; // 00000000000000000001010011010000
  cout<<__builtin_clz(x)<<"\n"; // numero de ceros a la izquierda
  cout<<__builtin_ctz(x)<<"\n"; // numero de ceros a la derecha
  cout<<__builtin_popcount(x)<<"\n"; // numero de bits prendidos
  cout<<__builtin_ffs(x)<<"\n"; // posición del primer bit prendido (lsb+1)
  return 0;
}