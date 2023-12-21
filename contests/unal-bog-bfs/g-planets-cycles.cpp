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
int teleport[2*100002];
int ciclos[2*100002];
bool visitados[2*100002];
 
void dfs(queue<int>& camino,int act, int& longitud){
  camino.push(act);
  if(visitados[act]){
    longitud+=ciclos[act];return;
  }visitados[act]=true;longitud++;
  dfs(camino, teleport[act], longitud);
}
 
void ajustarCiclos(queue<int> camino, int longitud){
  int ajustar=1;
  // while(!camino.empty()){
  //   cout<<camino.front()<<" ";camino.pop();
  // }cout<<"\n";
  while(!camino.empty()){
  	if(camino.front()==camino.back())ajustar=0;
  	ciclos[camino.front()]=longitud;longitud-=ajustar;
  	camino.pop();
  }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>teleport[i];
  for(int i=1;i<=n;i++){
    queue<int> camino;
    if(!visitados[i]){
      int longitud=0;
      dfs(camino,i,longitud);
      // cout<<longitud<<"\n";
      ajustarCiclos(camino, longitud);
    }
  }
  for(int i=1;i<n;i++)cout<<ciclos[i]<<" ";
  cout<<ciclos[n]<<"\n";
  return 0;
}
