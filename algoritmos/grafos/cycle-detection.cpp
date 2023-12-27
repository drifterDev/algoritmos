// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef vector<int> vi;
vector<vi> adj;
vector<bool> visited;
vi parent;
int cycle_start, cycle_end;
int n;

bool dfs(int v, int par){ 
  visited[v]=true;
  for(int u:adj[v]){
    if(u==par)continue;
    if(visited[u]){
      cycle_end=v;
      cycle_start=u;
      return true;
    }
    parent[u]=v;
    if(dfs(u,parent[u]))return true;
  }
  return false;
}

void find_cycle() {
  visited.assign(n, false);
  parent.assign(n, -1);
  cycle_start=-1;
  for(int v=0;v<n;++v){
    if(!visited[v] && dfs(v, parent[v]))break;
  }

  if(cycle_start==-1)cout<<"Acyclic\n";
  else{
    vi cycle;
    cycle.PB(cycle_start);
    for(int v=cycle_end;v!=cycle_start;v=parent[v])cycle.PB(v);
    cycle.PB(cycle_start);
    cout<<"Cycle found: ";
    for(int v:cycle)cout<<v<<" ";
    cout<<"\n";
  }
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  int m;
  cin>>n>>m;
  adj.resize(n);
  for(int i=0,u,v;i<m;++i){
    cin>>u>>v;
    adj[u-1].PB(v-1);
  }
  find_cycle();
  return 0;
}