#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) x.size())
typedef long long ll;
const int MOD = 1e9+7;

ll binpow(ll a, ll b, ll m=MOD);
void primeFactors(ll n, map<ll, int>& f);
ll mod(ll a){return ((a%MOD)+MOD)%MOD;}
ll mul(ll a, ll b){return mod(mod(a)*mod(b));}

// d(n) = (a1+1)*(a2+1)*...*(ak+1)
ll numDiv(ll n){
	ll ans=1;
	map<ll, int> f;
	primeFactors(n,f);
	for(auto& [_,pot]:f)ans*=(pot+1);
	return ans;
}

// sigma(n) = (p1^(a1+1)-1)/(p1-1) * (p2^(a2+1)-1)/(p2-1) * ... * (pk^(ak+1)-1)/(pk-1)
// suma divisores a la xth potencia
ll sumDiv(ll n){
	ll ans=1,potencia=1;         
	map<ll, int> f;
	primeFactors(n,f);
	for(auto& [num, pot]:f)
		ans*=(binpow(num,(pot+1)*potencia)-1)/(num-1);
	return ans;
}

ll productDiv(map<int, ll>& f){
	// implementar binpow
	ll pi=1,res=1;
	for(auto& [num, pot]:f){
		ll p=binpow(num, pot*(pot+1)/2);
		res=mul(binpow(res, pot+1),binpow(p, pi));
		pi=(pi*(pot+1))%(MOD-1);
	}
	return res;
}

// si a y b son coprimos, entonces: 
// sigma(a*b) = sigma(a)*sigma(b)
// d(a*b) = d(a)*d(b)
