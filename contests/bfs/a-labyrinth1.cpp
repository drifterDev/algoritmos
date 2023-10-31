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
char mapa[2001][2001];
bool visitados[2001][2001];

void bfs(int x, int y, int l, int r, int& res, int n, int m){
  deque<vl> q;q.push_front({x,y,l,r});
  while(!q.empty()){
    vl act=q.front();q.pop_front();
    if(act[0]<0 || act[0]>=n || act[1]<0 || act[1]>=m)continue;
    if(act[2]<0 || act[3]<0)continue;
    if(mapa[act[0]][act[1]]=='*')continue;
    if(visitados[act[0]][act[1]]==true)continue;
    visitados[act[0]][act[1]]=true;
    mapa[act[0]][act[1]]='-';res++;
    q.push_front({act[0]+1, act[1], act[2], act[3]});
    q.push_front({act[0]-1, act[1], act[2], act[3]});
    q.push_back({act[0], act[1]-1, act[2]-1, act[3]});
    q.push_back({act[0], act[1]+1, act[2], act[3]-1});
  }
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
int n,m,x,y,l,r;cin>>n>>m;
cin>>x>>y;cin>>l>>r;x--;y--;
for(int i=0;i<n;i++){
  for(int j=0;j<m;j++)cin>>mapa[i][j];
}
int res=0;
bfs(x,y,l,r, res, n, m);
cout<<res<<"\n";
// for(int i=0;i<n;i++){
//   for(int j=0;j<m;j++)cout<<mapa[i][j];
//   cout<<"\n";
// }
return 0;
}