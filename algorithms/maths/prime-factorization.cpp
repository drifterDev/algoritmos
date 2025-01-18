#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) x.size())
typedef long long ll;

vector<ll> primes;
// O(sqrt(n)/log(sqrt(n)))
void fact(ll n, map<ll, int>& f){
	for(int i=0;i<sz(primes) && primes[i]*primes[i]<=n;++i) 
		while(n%primes[i]==0ll)f[primes[i]]++,n/=primes[i];
	if(n>1)f[n]++;
}
