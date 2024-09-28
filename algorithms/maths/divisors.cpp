#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) x.size())
typedef long long ll;
const int MOD = 1e9+7;

ll binpow(ll a, ll b, ll m);
void primeFactors(ll n, map<ll, int>& f);

// d(n) = (a1+1)*(a2+1)*...*(ak+1)
ll numDiv(ll n){
	ll ans=1;
	map<ll, int> f;
	primeFactors(n,f);
	for(auto &x:f)ans*=(x.second+1);
	return ans;
}

// sigma(n) = (p1^(a1+1)-1)/(p1-1) * (p2^(a2+1)-1)/(p2-1) * ... * (pk^(ak+1)-1)/(pk-1)
// suma divisores a la xth potencia
ll sumDiv(ll n){
	ll ans=1,pot=1;         
	map<ll, int> f;
	primeFactors(n,f);
	for(auto &x:f)
		ans*=(binpow(x.first,(x.second+1)*pot,MOD)-1)/(x.first-1);
	return ans;
}

ll productDiv(map<int, ll>& f){
	// implementar binpow
	ll pi=1,res=1;
	for(auto x:f){
		ll p=binpow(x.first, x.second*(x.second+1)/2,MOD);
		res=(binpow(res, x.second+1,MOD)*binpow(p, pi,MOD))%MOD;
		pi=(pi*(x.second+1))%(MOD-1);
	}
	return res;
}

// secondi a y b son coprimos, entonces: 
// sigma(a*b) = sigma(a)*sigma(b)
// d(a*b) = d(a)*d(b)
