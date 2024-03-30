// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;

ll _sieve_size;
bitset<10000001> bs;
vl p;
void sieve(ll upperbound) {
  _sieve_size= upperbound+1;
  bs.set();
  bs[0] = bs[1] = 0;
  for (ll i = 2; i < _sieve_size; ++i) if (bs[i]) {
    for (ll j = i*i; j < _sieve_size; j += i) bs[j] =0;
    p.push_back(i);
  }
}

vl primeFactors(ll n) {
	vl factors;
	for (ll i = 0; (i < (ll)p.size()) && (p[i]*p[i] <=n); ++i){
    ll act=0;
		while (n%p[i] == 0) { 
			n/=p[i]; 
      act=p[i];
		}
    if(act!=0)factors.push_back(p[i]);
  }
	if (n != 1) factors.push_back(n);
	return factors;
}


int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
sieve(10000000);
ll n;cin>>n;
while(n!=0){
  n=abs(n);
  if(n==1)cout<<"-1\n";
  else{
  vl res=primeFactors(n);
  ll lon=sz(res);
  if(lon>1)cout<<res[lon-1]<<"\n";
  else cout<<"-1\n";
  }
  cin>>n;

}
return 0;
}

