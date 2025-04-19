#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD;

ll gcd(int a, int b, int x, int y);
ll binpow(ll a, ll b, ll m);

ll mod(ll a, ll m){return ((a%m)+m)%m;}
ll inv(ll a, ll m){return binpow(a, m-2ll, m);}

ll mod(ll a){return ((a%MOD)+MOD)%MOD;}
ll add(ll a, ll b){return mod(mod(a)+mod(b));}
ll mul(ll a, ll b){return mod(mod(a)*mod(b));}

int mod(int a, int m){return ((a%m)+m)%m;}
int add(int a, int b, int m){return a+b>=m?a+b-m:a+b;}
int mul(int a, int b, int m){return ll(a)*b%m;} 

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
void inv(ll m){
	inverso[1]=1;
	for(int i=2;i<=n;++i)
		inverso[i]=(m-(m/i)*inverso[m%i]%m)%m;
}
