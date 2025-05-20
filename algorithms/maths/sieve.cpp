#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) x.size())
typedef long long ll;

// O(n*log(log(n)))
vector<ll> primes;
vector<bool> is_prime;
void sieve(ll n){
	is_prime.assign(n+1,true);
	for(ll i=2;i<=n;++i){
		if(!is_prime[i])continue;
		for(ll j=i*i;j<=n;j+=i)is_prime[j]=false;
		primes.push_back(i);
	}
}

// criba lineal
vector<int> f;
vector<int> primes;
vector<bool> is_composite;
void sieve(int n){
	f.assign(n+1,1);
	is_composite.assign(n+1,false);
	// caso base en 1, phi[1]=1;
	for(int i=2;i<n;++i){
		if(!is_composite[i]){ // i es primo
			primes.push_back(i);
			// caso para primos, phi[i]=i-1;
		}
		for(int j=0;j<sz(primes) && 1ll*i*primes[j]<1ll*n;++j){
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