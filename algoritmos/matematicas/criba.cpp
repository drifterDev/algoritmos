#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
#define PB push_back
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;

// O(n*log(log(n)))
vl primos;
ll lon_criba;
vector<bool> is_prime;
void criba(ll n){
	lon_criba=n;
	is_prime.assign(n+1,true);
	for(ll i=2;i<=n;++i){
		if(!is_prime[i])continue;
		for(ll j=1ll*i*i;j<=n;j+=i)is_prime[j]=false;
		primos.push_back(i);
	}
}

// O((R-L+1)*log(log(R))+sqrt(R)*log(log(R)))
vl primes;
vector<bool> segmentedSieve(ll L, ll R) {
	// generate all primes up to sqrt(R)
	ll lim=sqrt(R);
	vector<bool> mark(lim+1, false);
	for (ll i=2;i<=lim;++i){
		if (!mark[i]){
			for(ll j=i*i;j<=lim;j+=i)mark[j]=true;
			primes.PB(i);
		}
	}

	vector<bool> isPrime(R-L+1,true);
	for(ll i:primes)
		for(ll j=max(i*i,(L+i-1)/i*i);j<=R;j+=i)
			isPrime[j-L]=false;
	if(L==1)
		isPrime[0]=false;
	return isPrime;
}

// criba lineal
const int maxn = 1e5;
vector<int> prime;
bool is_composite[maxn];
int f[maxn];

void sieve (int n) {
	fill (is_composite, is_composite+n, false);
	// caso base en 1, phi[1]=1;
	for(int i=2;i<n;++i){
		if(!is_composite[i]){ // i es primo
			prime.push_back(i);
			// caso para primos, phi[i]=i-1;
		}
		for(int j=0;j<prime.size() && i*prime[j]<n;++j){
			is_composite[i*prime[j]]=true;
			if (i % prime[j] == 0) {
				// caso prime[j] divide a i, phi[i * prime[j]] = phi[i] * prime[j];	
				break;
			} else {
				// caso prime[j] no divide a i, phi[i * prime[j]] = phi[i] * phi[prime[j]];
			}
		}
	}
}