// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
bool visited[n];
int distance[n];

void bfs(vector<vi>& adj, int s){
  visited[s]=true;
  distance[s]=0;
  queue<int> q;q.push(s);
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

void bfs01(vector<vi>& adj, int s){
  distance[s]=0;
  deque<int> dq;
  dq.push_front(s);
  while(!dq.empty()){
    int s=dq.front();dq.pop_front();
    for(auto x:adj[s]){
      int u=x.F,w=x.S;
      if(distance[u]>distance[s]+w){
        distance[u]=distance[s]+w;
        if(w==0)dq.push_front(u);
        else dq.push_back(u);
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}