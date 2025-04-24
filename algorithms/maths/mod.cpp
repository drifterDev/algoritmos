#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll binpow(ll a, ll b, ll m);
ll gcd(ll a, ll b, ll &x, ll &y);

const ll MOD = 1e9+7;
ll mod(ll a){return ((a%MOD)+MOD)%MOD;}
ll add(ll a, ll b){return mod(mod(a)+mod(b));}
ll mul(ll a, ll b){return mod(mod(a)*mod(b));}
ll inv(ll a){return binpow(a, MOD-2ll, MOD);}

// mod changes
ll mod(ll a, ll m){return ((a%m)+m)%m;}
ll add(ll a, ll b, ll m){return mod(mod(a,m)+mod(b,m),m);}
ll mul(ll a, ll b, ll m){return mod(mod(a,m)*mod(b,m),m);}
ll inv(ll a, ll m){return binpow(a, m-2ll, m);}

// int
const int MOD = 1e9+7;
int mod(int a){return ((a%MOD)+MOD)%MOD;}
int add(int a, int b){return a+b>=MOD?a+b-MOD:a+b;}
int mul(int a, int b){return ll(a)*b%MOD;} 
int inv(int a){return binpow(a,MOD-2,MOD);}

// mod changes
int mod(int a, int m){return ((a%m)+m)%m;}
int add(int a, int b, int m){return a+b>=m?a+b-m:a+b;}
int mul(int a, int b, int m){return ll(a)*b%m;} 
int inv(int a, int m){return binpow(a,m-2,m);}

// O(log(min(a, b)) - no primos (b y m coprimos)
ll inv(ll b, ll m){
	ll x,y;
	ll d=gcd(b, m, x, y); 
	if(d!=1)return -1;	// error
	return mod(x, m);
}

// Calcular el inv de [2,m)
const int n=1e6;
ll inverso[n+1];
void invN(ll m){
	inverso[1]=1;
	for(int i=2;i<=n;++i)
		inverso[i]=(m-(m/i)*inverso[m%i]%m)%m;
}
