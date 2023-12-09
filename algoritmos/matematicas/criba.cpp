// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
#define F first
#define S second
#define PB push_back
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;

// O(n*log(log(n)))
ll lon_criba;
bitset<1000001> bs;vl p;
void sieve(ll tope){
  lon_criba=tope+1;
  bs.set();
  bs[0]=bs[1]=0;
  for (ll i=2;i<lon_criba;++i)
    if(bs[i]){
      for (ll j = i * i; j < lon_criba; j += i)bs[j] = 0;
      p.PB(i);
    }
}

// O(n*log(log(n)))
vl primos;
void criba(ll n){
  vector<bool> is_prime(n+1, true);
  for(ll i=2;i<=n;++i){
    if(is_prime[i]){
      for(ll j=i*i;j<=n;j+=i)is_prime[j]=false;
      primos.PB(i);
    }
  }
}

// O((R-L+1)*log(log(R))+sqrt(R)*log(log(sqrt(R))))
vector<bool> segmentedSieve(ll L, ll R) {
  // generate all primes up to sqrt(R)
  vl primes;
  ll lim=sqrt(R);
  vector<bool> mark(lim + 1, false);

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

// Criba lineal
vi criba_lineal(const int N=10000000){
  vi lp(N+1),pr;
  for(int i=2;i<=N;++i){
    if(lp[i]==0){
      lp[i]=i;
      pr.PB(i);
    }
    for(int j=0;i*pr[j]<=N;++j){
        lp[i*pr[j]]=pr[j];
        if(pr[j]==lp[i])break;
    }
  }
  return pr;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a=10,b=120;
  vector<bool> primes = segmentedSieve(a,b);
  for(int i=0;i<sz(primes);++i){
    if(primes[i])cout<<a+i<<" ";
  }
  return 0;
}