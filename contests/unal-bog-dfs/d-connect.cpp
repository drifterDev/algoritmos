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
vii adj1, adj2;

void dfs(int x, int y, vector<vector<char>>& mapa, vii& adj){
  map<ii, bool> visitados;
  visitados[{x,y}] = true;
  queue<ii> q;q.push({x,y});
  adj.push_back({x,y});
  while(!q.empty()){
    ii act=q.front();q.pop();
    for(int i=0;i<4;i++){
      int nx=act.first+dirx[i];
      int ny=act.second+diry[i];
      if(nx>=0 && nx<sz(mapa) && ny>=0 && ny<sz(mapa)){
        if(!visitados[{nx,ny}] && mapa[nx][ny]!='1'){
          // cout<<nx<<" "<<ny<<"\n";
          visitados[{nx,ny}] = true;
          q.push({nx,ny});
          adj.push_back({nx,ny});
        }
      }
    }
  }
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
int n;cin>>n;
int x1,x2,y1,y2;
cin>>x1>>y1>>x2>>y2;
vector<vector<char>> mapa(n,vector<char>(n));
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>mapa[i][j];
    }
}
// for(int i=0;i<n;i++){
//     for(int j=0;j<n;j++){
//         cout<<mapa[i][j]<<" ";
//     }cout<<" \n";
// }
x1--;y1--;x2--;y2--;
dfs(x1,y1,mapa,adj1);
// cout<<"\n";
dfs(x2,y2,mapa,adj2);
ll res=INFL;
for(int i=0;i<sz(adj1);i++){
  // cout<<adj1[i].first<<" "<<adj1[i].second<<"\n";
  for(int j=0;j<sz(adj2);j++){
    ll act=pow(adj1[i].first-adj2[j].first, 2);
    act+=pow(adj1[i].second-adj2[j].second, 2);
    res=min(res, act);
  }
}cout<<res<<"\n";
return 0;
}