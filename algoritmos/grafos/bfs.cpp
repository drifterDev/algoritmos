// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define S second
#define F first
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int n=100;
vector<bool> visited(n);
vector<int> dist(n);

// O(n+m)
void bfs(vector<vi>& adj, int s){
  visited[s]=true;
  dist[s]=0;
  queue<int> q;q.push(s);
  while(!q.empty()){
    int s=q.front();q.pop();
    for(auto u:adj[s]){
      if (visited[u])continue;
      visited[u]=true;
      dist[u]=dist[s]+1;
      q.push(u);
    }
  }
}

void bfs01(vector<vii>& adj, int s){
  dist[s]=0;
  deque<int> dq;
  dq.push_front(s);
  while(!dq.empty()){
    int s=dq.front();dq.pop_front();
    for(auto x:adj[s]){
      int u=x.F,w=x.S;
      if(dist[u]>dist[s]+w){
        dist[u]=dist[s]+w;
        if(w==0)dq.push_front(u);
        else dq.push_back(u);
      }
    }
  }
}