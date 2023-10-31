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
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};


vi prefix_function(vi s){
  int n=sz(s);
  vi pi(n);
  for(int i=1;i<n;i++) {
    int j=pi[i-1];
    while(j>0 && s[i]!=s[j])j=pi[j-1];
    if (s[i]==s[j])j++;
    pi[i]=j;
  }
  return pi;
}

int matches=0;
void kmp(vi &t, vi &p){ 
  vi phi=prefix_function(p);
  for(int i=0,j=0;i<sz(t);i++){
    while(j>0 && t[i]!=p[j])j=phi[j-1];
    if(t[i]==p[j])j++;
    if(j==sz(p)){
      cout<<i-j+2<<"\n"; 
      matches++;
      return;
    }
  }
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
int k,n,m;cin>>k;
while(k--){
  cin>>n>>m;
  vi t(n),p(m);
  for(int i=0;i<n;i++)cin>>t[i];
  for(int i=0;i<m;i++)cin>>p[i];
  matches=0;
  kmp(t,p);
  if(matches==0)cout<<"-1\n";
}
return 0;
}