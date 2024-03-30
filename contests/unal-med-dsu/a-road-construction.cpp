// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;
 
struct dsu{
  vl parents,sizes;
  ll cantSets;
  ll maxSz;

  dsu(ll sz){
    parents.assign(sz, 0);
    sizes.assign(sz, 1);
    cantSets=sz;
    maxSz=1;
    for (int i = 0; i<sz; i++) parents[i] = i;
  }

  ll findSet(ll v) {
    if (v == parents[v]) return v;
    return parents[v] = findSet(parents[v]);
  }

  bool isSameSet(ll i, ll j) {return findSet(i) == findSet(j);}

  void unionSets(ll a, ll b) {
    a = findSet(a);
    b = findSet(b);
    if (a!=b) {
      if (sizes[a] < sizes[b]) swap(a, b);
      parents[b] = a;
      sizes[a] += sizes[b];
      maxSz = max(maxSz,sizes[a]);
      cantSets--;
    }
  }
};
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20) << fixed;
  int n, m;cin>>n>>m;
  dsu d(n);
  while(m--){
    int a,b;cin>>a>>b;
    d.unionSets(a-1,b-1);
    cout<<d.cantSets<<" "<<d.maxSz<<"\n";
  }
  return 0;
}
