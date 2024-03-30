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
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

ll _sieve_size;
bitset<1000001> bs;
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

int numDiv(ll n) {
  int ans = 1;
  for (int i = 0; (i < (int)p.size()) && (p[i]*p[i] <=n); ++i) {
    int power = 0; 
    while (n%p[i] == 0) {
      n /=p[i]; ++power; 
    }
    ans *= power+1;
  }
  return (n != 1) ? 2*ans : ans;
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
sieve(1000000);
ll t,a,b;cin>>t;
while(t--){
  cin>>a>>b;
  cout<<numDiv(__gcd(a,b))<<"\n";
}
return 0;
}