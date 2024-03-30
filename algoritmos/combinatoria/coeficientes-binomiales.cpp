// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int N = 100000;
typedef long long ll;
ll fact[N];

ll inv(ll x, ll m);
// nCr = n!/(r!*(n-r)!)

// O(log MOD)
ll c(int n, int r){
	if(n<r)return 0;
	return (((fact[n]*inv(fact[r],MOD))%MOD)*inv(fact[n-r],MOD))%MOD;
}

// O(min(r, n-r))
ll c(ll n, ll r){
	if(r<0 || n<r)return 0;
	r=min(r, n-r);
	ll ans=1;
	for(int i=1;i<=r;++i){
		ans=ans*(n-i+1)/i;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	fact[0]=1;
	for(int i=1;i<N;++i)
		fact[i]=((fact[i-1]%MOD)*i)%MOD;
	return 0;
}
