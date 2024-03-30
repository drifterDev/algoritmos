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

void dfs(vector<bool>& visited, vector<vi>& adj, int act, int& res, vi& tmp){
  visited[act]=true;res++;
  tmp.push_back(act);
  for(int v:adj[act]){
      if(visited[v])continue;
      // cout<<act+1<<" "<<v+1<<"\n";
      dfs(visited, adj, v, res, tmp);
    }
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n,m,k,tmp,tmp2;cin>>n>>m;
vector<vi> adj(n);
for(int i=0;i<m;i++){
  cin>>k;
  if(k==0)continue;
  else if(k==1){
    cin>>k;continue;
  }
  cin>>tmp;
  for(int j=1;j<k;j++){
    cin>>tmp2;
    adj[tmp-1].push_back(tmp2-1);
    adj[tmp2-1].push_back(tmp-1);
    tmp=tmp2;
  }
}
// for(int i=0;i<n;i++){
//   for(int v:adj[i]){
//     cout<<v<<" ";
//   }cout<<"\n";
// }
vi ans(n,0);
vector<bool> visited(n, false);
for(int i=0;i<n;i++){
  if(visited[i])continue;
  vi tmp;int res=0;
  dfs(visited, adj, i, res, tmp);
  for(int x:tmp)ans[x]=res;
}

for(int i=0;i<n-1;i++)cout<<ans[i]<<" ";
cout<<ans[n-1]<<"\n";
return 0;
}