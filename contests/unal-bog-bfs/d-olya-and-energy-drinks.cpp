// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout<<#x<<"="<<x<<'\n'
#define trace(x) cerr<<#x<<"="<<x<<'\n'
#define sz(arr) ((int) arr.size())
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
char mapa[1000][1000];
int dist[1000][1000];
bool visitados[1000][1000];

void bfs(int n, int m, int k,ii begin, ii end){
  queue<ii> q;q.push(begin);
  dist[begin.first][begin.second]=0;
  visitados[begin.first][begin.second]=true;
  while(!q.empty()){
    ii act=q.front();q.pop();
    int x1=act.first,y1=act.second;
    for(int i=0;i<4;i++){
      for(int j=1;j<=k;j++){
        int x2=x1+(dirx[i]*j),y2=y1+(diry[i]*j);
        if(x2>=0 && x2<n && y2>=0 && y2<m && !visitados[x2][y2] && mapa[x2][y2]!='#'){
          visitados[x2][y2]=true;
          dist[x2][y2]=dist[x1][y1]+1;
          if(x2==end.first && y2==end.second)return;
          q.push({x2,y2});
        }else if(x2>=0 && x2<n && y2>=0 && y2<m && mapa[x2][y2]=='#')break;
      }
    }
  }
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n,m,k;cin>>n>>m>>k;
for(int i=0;i<n;i++){
  for(int j=0;j<m;j++){
    cin>>mapa[i][j];
  }
}
int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
x1--;y1--;x2--;y2--;
if(x1==x2 && y1==y2){
  cout<<"0\n";return 0;
}
bfs(n,m,k,{x1,y1},{x2,y2});
if(dist[x2][y2])cout<<dist[x2][y2]<<"\n";
else cout<<"-1\n";
// for(int i=0;i<n;i++){
//   for(int j=0;j<m;j++){
//     cout<<dist[i][j]<<" ";
//   }cout<<"\n";
// }
return 0;
}