// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout<<#x<<"="<<x<<'\n'
#define trace(x) cerr<<#x<<"="<<x<<'\n'
#define sz(arr) ((int) arr.size())
#define len(str) ((int) str.length())
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define PB push_back
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;

vl primeFactors(ll n){
  vl factors;
  for(int i=0;sz(p) && (p[i]*p[i]<=n);++i){
    while(n%p[i]==0)n/=p[i];
    factors.PB(p[i]);
  }
  if(n!=1)factors.push_back(N);
  return factors;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  sieve(10000000);
  return 0;
}