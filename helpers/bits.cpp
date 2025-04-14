#include <bits/stdc++.h>
using namespace std;

// Si x es ll usar en vez de 1<< usar 1ll<< 

// a & b           -> Operacion AND
// a | b           -> Operacion OR
// a ^ b           -> Operacion XOR
// ~ a             -> Operacion NOT
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

// Devuelve el bit menos significativo prendido
int lsb(int n){return n&(-n);}

// optimiza el .count de los bitsets y el popcount
#pragma GCC target("popcnt")

int main() {
	for(int i=0;i<16;++i){
		cout<<lsb(i)<<" "<<bitset<4>(i)<<"\n";
	}

	// Funciones de gcc. Si n es ll agregar el sufijo ll -> (__builtin_clzll(x)).
	int x = 5328; // 00000000000000000001010011010000
	cout<<__builtin_clz(x)<<"\n"; // numero de ceros a la izquierda
	cout<<__builtin_ctz(x)<<"\n"; // numero de ceros a la derecha
	cout<<__builtin_popcount(x)<<"\n"; // numero de bits prendidos
	cout<<__builtin_parity(x)<<"\n"; // Paridad del numero de unos
	cout<<__builtin_ffs(x)<<"\n"; // posición del primer bit prendido (lsb+1)


	int m=14; // 1110
	// Todos los subconjuntos del conjunto O(2^n)
	for(int s=m;;s=(s-1)&m){
		cout<<bitset<4>(s)<<"\n";
		if(s==0)break;
	}
	// Ascendente
	for(int s=0;;s=s-m&m){ 
		cout<<bitset<4>(s)<<"\n";
		if(s==m)break;
	}

	// O(n^3)
	// for(int s=0;s<(1<<n);++s)
	//      for(int mask=s;;mask=(mask-1)&s){
				// if(mask==0)break;
	return 0;
}