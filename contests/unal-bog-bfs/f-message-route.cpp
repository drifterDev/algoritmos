// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
int camino[100002];
bool visitados[100002];
 
void bfs(vector<vi>& lista){
  queue<int> q;q.push(1);
  visitados[1]=true;
  while(!q.empty()){
    int act=q.front();q.pop();
    for(int nodo:lista[act]){
      if(visitados[nodo])continue;
      visitados[nodo]=true;
      camino[nodo]=act;
      q.push(nodo);
    }
  }
}
 
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n,m, a,b;cin>>n>>m;
vector<vi> lista(n+1,vi());
for(int i=0;i<m;i++){
  cin>>a>>b;
  lista[a].push_back(b);
  lista[b].push_back(a);
}
// for(int i=0;i<n+1;i++){
//   for(int j=0;j<sz(lista[i]);j++){
//     cout<<lista[i][j]<<" ";
//   }cout<<"\n";
// }
bfs(lista);
// for(int i=0;i<n+1;i++){
//   cout<<camino[i]<<" ";
// }cout<<"\n";
vi caminoFinal;
int act=n;
if(camino[act]!=0){
  while(act!=0){
  // cout<<act<<" ";
  caminoFinal.push_back(act);
  act=camino[act];
  // }cout<<1<<"\n";
  }
  int longitud=sz(caminoFinal);
  cout<<longitud<<"\n";
  for(int i=longitud-1;i>0;i--)cout<<caminoFinal[i]<<" ";
  cout<<caminoFinal[0]<<"\n";
}else{
  cout<<"IMPOSSIBLE\n";
}return 0;
}
