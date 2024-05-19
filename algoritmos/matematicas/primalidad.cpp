#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()
typedef long long ll;
bool is_prime[1000001];
vector<int> primos;
int lon_criba;

// O(sqrt(n))
bool isPrime(ll x){
	for(int d=2;1ll*d*d<=x;++d)if(x%d==0)return false;
	return x>=2;
}

// Con criba
// O(sqrt(n)/log(sqrt(n)))
bool isPrime(ll n){
	if(n<=lon_criba)return is_prime[n];
	for(int i=0;i<sz(primos) && 1ll*primos[i]*primos[i]<=n;++i)
		if(n%primos[i]==0)return false;
	return true;  
}  