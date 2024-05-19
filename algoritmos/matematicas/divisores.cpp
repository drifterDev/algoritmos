#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) x.size())
#define S second
#define F first
typedef long long ll;
const int MOD = 1e9+7;

ll binpow(ll a, ll b, ll m);
void primeFactors(ll n, map<ll, int>& f);

// d(n) = (a1+1)*(a2+1)*...*(ak+1)
ll numDiv(ll n){
    ll ans=1;
    map<ll, int> f;
    primeFactors(n,f);
    for(auto &x:f)ans*=(x.S+1);
    return ans;
}

// sigma(n) = (p1^(a1+1)-1)/(p1-1) * (p2^(a2+1)-1)/(p2-1) * ... * (pk^(ak+1)-1)/(pk-1)
ll sumDiv(ll n){
    ll ans=1;         
    map<ll, int> f;
    primeFactors(n,f);
    for(auto &x:f)
        ans*=(binpow(x.F,x.S+1,MOD)-1)/(x.F-1);
    return ans;
}

ll productDiv(map<int, ll>& f){
    // implementar binpow
    ll pi=1,res=1;
    for(auto x:f){
        ll p=binpow(x.F, x.S*(x.S+1)/2,MOD);
        res=(binpow(res, x.S+1,MOD)*binpow(p, pi,MOD))%MOD;
        pi=(pi*(x.S+1))%(MOD-1);
    }
    return res;
}

// Si a y b son coprimos, entonces: 
// sigma(a*b) = sigma(a)*sigma(b)
// d(a*b) = d(a)*d(b)
