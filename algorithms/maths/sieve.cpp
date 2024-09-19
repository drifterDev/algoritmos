#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;

// O(n*log(log(n)))
vl primess;
vector<bool> primes;
void sieve(ll n){
	primes.assign(n+1,true);
	for(ll i=2;i<=n;++i){
		if(!primes[i])continue;
		for(ll j=1ll*i*i;j<=n;j+=i)primes[j]=false;
		primess.push_back(i);
	}
}

// O((R-L+1)*log(log(R))+sqrt(R)*log(log(R)))
vl primess;
vector<bool> segmented_sieve(ll L, ll R) {
	// generate all primess up to sqrt(R)
	ll lim=sqrt(R);
	vector<bool> mark(lim+1, false);
	for (ll i=2;i<=lim;++i){
		if (!mark[i]){
			for(ll j=i*i;j<=lim;j+=i)mark[j]=true;
			primess.push_back(i);
		}
	}

	vector<bool> primes(R-L+1,true);
	for(ll i:primess)
		for(ll j=max(i*i,(L+i-1)/i*i);j<=R;j+=i)
			primes[j-L]=false;
	if(L==1)primes[0]=false;
	return primes;
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