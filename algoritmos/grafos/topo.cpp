// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef vector<int> vi;
int n,m;

void bfs(vector<vi>& adj, vi& grade, vi& order){
  queue<int> q;
  for(int i=0;i<n;i++)if(!grade[i])q.push(i);
  while(!q.empty()){
    int act=q.front();q.pop();
    order.PB(act);
    for(int v:adj[act]){
      grade[v]--;
      if(grade[v]==0)q.push(v);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  cin>>n>>m;
  vector<vi> adj(n);
  vi grade(n), order;
  for(int i=0,a,b;i<m;++i){
    cin>>a>>b;
    adj[a].PB(b);
    grade[b]++;
  }
  bfs(adj,grade,order);
  for(int x:order)cout<<x<<" ";
  cout<<"\n";
  return 0;
}