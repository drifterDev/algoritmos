#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) x.size())
typedef long long ll;

// O(log(n))
// Sieve() and save the lowest prime factor 

// O(sqrt(n)/log(sqrt(n)))
vector<ll> primes;
void fact(ll n, map<ll, int>& f){
	for(int i=0;i<sz(primes) && primes[i]*primes[i]<=n;++i) 
		while(n%primes[i]==0ll)f[primes[i]]++,n/=primes[i];
	if(n>1)f[n]++;
}
