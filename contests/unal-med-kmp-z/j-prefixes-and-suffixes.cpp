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

vi prefix_function(string s){
  int n=len(s);
  vi pi(n);
  for(int i=1;i<n;i++) {
    int j=pi[i-1];
    while(j>0 && s[i]!=s[j])j=pi[j-1];
    if (s[i]==s[j])j++;
    pi[i]=j;
  }
  return pi;
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
string s;cin>>s;
vi pi=prefix_function(s);
// for(int i=0;i<len(s);i++)cout<<pi[i]<<" ";
// cout<<"\n";
int n=len(s);
vi ans(n + 1);
for(int i=0;i<n;i++)ans[pi[i]]++;
for(int i=n-1;i>0;i--)ans[pi[i-1]]+=ans[i];
for(int i=0;i<=n;i++)ans[i]++;
vii res;
int act=n-1;
while(pi[act]!=0){
  if(pi[act]==1)break;
  res.push_back({pi[act], ans[pi[act]]});
  act=pi[act]-1;
}
if(s[0]==s[n-1])res.push_back({1,ans[1]});
if(n!=1)res.push_back({n,ans[n]});
sort(all(res));
cout<<sz(res)<<"\n";
for(auto i:res){
  cout<<i.first<<" "<<i.second<<"\n";
}

return 0;
}