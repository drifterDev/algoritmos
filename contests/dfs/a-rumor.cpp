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

void dfs(int u, vector<bool> &visited, vector<vi> &adj){
  visited[u]=true;
  for(int v:adj[u]){
    if(!visited[v])dfs(v,visited,adj);
  }
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
int n,m,tmp,tmp2;cin>>n>>m;
vii nums;
vector<vi> adj(n+1);
for(int i=1;i<=n;i++){
  cin>>tmp;nums.push_back({tmp,i});
}sort(all(nums));ll res=0;
vector<bool> visited(n+1, false);
for(int i=0;i<m;i++){
  cin>>tmp>>tmp2;
  adj[tmp].push_back(tmp2);
  adj[tmp2].push_back(tmp);
}
for(auto act:nums){
  if(!visited[act.second]){
    res+=act.first;
    dfs(act.second,visited,adj);
  }
}
cout<<res<<"\n";
return 0;
}