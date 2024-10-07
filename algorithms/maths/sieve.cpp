#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;

// O(n*log(log(n)))
vl primes;
vector<bool> is_prime;
void sieve(ll n){
	is_prime.assign(n+1,true);
	for(ll i=2;i<=n;++i){
		if(!is_prime[i])continue;
		for(ll j=1ll*i*i;j<=n;j+=i)is_prime[j]=false;
		primes.push_back(i);
	}
}

// criba lineal
const int maxn = 1e5;
vector<int> primes;
bool is_composite[maxn];
int f[maxn];
void sieve(int n){
	fill(is_composite, is_composite+n, false);
	// caso base en 1, phi[1]=1;
	for(int i=2;i<n;++i){
		if(!is_composite[i]){ // i es primo
			primes.push_back(i);
			// caso para primos, phi[i]=i-1;
		}
		for(int j=0;j<primes.size() && 1ll*i*primes[j]<1ll*n;++j){
			is_composite[i*primes[j]]=true;
			if(i%primes[j]==0){
				// caso primes[j] divide a i, phi[i * primes[j]] = phi[i] * primes[j];	
				break;
			}else{
				// caso primes[j] no divide a i, phi[i * primes[j]] = phi[i] * phi[primes[j]];
			}
		}
	}
}