// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vi adj[n];
bool visited[n];

void dfs(int s) {
  if(visited[s])return;
  visited[s]=true;
  for(auto u:adj[s])dfs(u);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}