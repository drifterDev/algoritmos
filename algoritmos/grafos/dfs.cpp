// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int n=100;
vi adj[n];
bool visited[n];

// O(n+m)
void dfs(int s) {
  if(visited[s])return;
  visited[s]=true;
  for(auto u:adj[s])dfs(u);
}