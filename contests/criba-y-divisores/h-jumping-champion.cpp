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

ll calculate(ll l, ll r){
  auto it = lower_bound(p.begin(), p.end(), l);
  ll index=distance(p.begin(), it);
  unordered_map<ll, ll>mapa;ll maximo=0;ll count=0;
  for(ll i=index;i<=78498;i++){
    if(p[i]>r || p[i+1]>r)break;
    //cout<<p[i]<<" "<<p[i+1]<<" = "<<p[i+1]-p[i]<<"\n";
    mapa[p[i+1]-p[i]]++;
  }
  for (const auto& key:mapa) {
    if(maximo<key.second){
      maximo=key.second;
      count=key.first;
    }else if(maximo==key.second)count=0;
    //cout<<key.first<<" "<<key.second<<"\n";
  }
  if (count==0)return 0;
  return count;
}


int main() {
ios::sync_with_stdio(false);
cin.tie(0);
sieve(1000000);
ll t,l,r,res;cin>>t;
while(t--){
  cin>>l>>r;res=calculate(l,r);
  if (res!=0)cout<<"The jumping champion is "<<res<<"\n";
  else cout<<"No jumping champion\n";
}
return 0;
}