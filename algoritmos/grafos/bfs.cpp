// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vi adj[n];
queue<int> q;
bool visited[n];
int distance[n];

void bfs(int x){
  visited[x]=true;
  distance[x]=0;
  q.push(x);
  while(!q.empty()){
    int s=q.front();q.pop();
    for(auto u:adj[s]){
      if (visited[u])continue;
      visited[u]=true;
      distance[u]=distance[s]+1;
      q.push(u);
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}