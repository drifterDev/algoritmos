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

//Implementación directa
vector<ll> prefix_function(string s){
  ll n=s.length();
  vector<ll> pi(n);
  for (ll i=0;i<n;i++){
    for(ll k=0; k<=i;k++){
      if(s.substr(0,k)==s.substr(i-k+1,k)){
        pi[i]=k;
      }
    }
  }
  return pi;
}

//Otra implementación
vector<ll> prefix_function2(string s){
  ll n=(ll)s.length();
  vector<ll> pi(n,0);
  for(ll i=1;i<n;i++){
    ll j=pi[i-1];
    while(j>0 && s[i]!=s[j]){
      j=pi[j-1];
    }
    if(s[i]==s[j]){
      j++;
    }
    pi[i]=j;
  }
  return pi;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}