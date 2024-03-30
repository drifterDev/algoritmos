// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int n=100;
ll cat[n+1];

ll inv(ll x, ll m);

// O(n*log(MOD))
void init(){
	// Implementar inverso modular
	cat[0]=1;
	for(int i=1;i<=n;++i){
		cat[i]=(((4*i-2)%MOD)*(cat[i-1]%MOD))%MOD;
		cat[i]=(cat[i]*inv(i+1,MOD))%MOD;
	}
}
