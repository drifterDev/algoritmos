// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) x.size())
typedef long long ll;
typedef vector<ll> vl;

ll compute_hash(string const& s) {
  const int p = 31; 
  const int m = 1e9+9; 
  ll hash_value=0;
  ll p_pow=1;
  for (char c:s) {
    hash_value=(hash_value+(c-'a'+1)*p_pow)%m;
    p_pow=(p_pow*p)%m;
  }
  return hash_value;
}

// Cuenta la cantidad de formas de formar un string s con los strings 
// O(n*sqrt(m))
ll count_forms(string s, vector<string>& strings){
  set<ll> hashes;
  for(auto x:strings)hashes.insert(compute_hash(x));
  int n=sz(s);
  vl dp(n+1,0);
  dp[0]=1;
  for(int i=1;i<=n;++i){
    for(int j=1;j<=i;++j){
      if(hashes.count(compute_hash(s.substr(j-1,i-j+1)))){
        dp[i]+=dp[j-1];
      }
    }
  }
  return dp[n];
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  string s;cin>>s;
  int m;cin>>m;
  vector<string> strings(m);
  for(int i=0;i<m;++i)cin>>strings[i];
  cout<<count_forms(s,strings)<<"\n";
  return 0;
}