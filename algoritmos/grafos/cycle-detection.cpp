// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef vector<int> vi;
int cycle_start, cycle_end,n;
vector<vi> adj;
vi parent;

vector<bool> visited; // No dirigidos 
vi color; // Dirigidos

// Dirigidos
bool dfs(int v){
  color[v]=1;
  for(int u:adj[v]){
    if(color[u]==0){
      parent[u]=v;
      if(dfs(u))return true;
    }else if(color[u]==1){
      cycle_end=v;
      cycle_start=u;
      return true;
    }
  }
  color[v]=2;
  return false;
}

// No dirigidos
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

// O(m)
void find_cycle(){
  color.assign(n, 0); // Dirigidos
  visited.assign(n, false); // No dirigidos
  parent.assign(n, -1);
  cycle_start=-1;
  for(int v=0;v<n;++v){
    // Dirigidos
    if(color[v]==0){
      if(dfs(v))break;
    }
    // No dirigidos
    // if(!visited[v]){
    //   if(dfs(v, parent[v]))break;
    // }
  }

  if(cycle_start==-1)cout<<"IMPOSSIBLE\n";
  else{
    vi cycle;
    cycle.PB(cycle_start);
    for(int v=cycle_end;v!=cycle_start;v=parent[v])cycle.PB(v);
    cycle.PB(cycle_start);
    reverse(cycle.begin(),cycle.end()); // Dirigidos
    cout<<cycle.size()<<"\n";
    for(int v:cycle)cout<<v+1<<" ";
    cout<<"\n";
  }
}

// Contar ciclos, para grafos funcionales
const int MAXN = 1e5;
bool visited[MAXN];
bool on_stack[MAXN];
int number_of_cycles = 0;
int next_node[MAXN];

void dfs(int n) {
	visited[n] = on_stack[n] = true;
	int u = next_node[n];
	if (on_stack[u]) {
		number_of_cycles++;
	} else if (!visited[u]) {
		dfs(u);
	}
	on_stack[n] = false;
}

int main() {
	// read input, etc
	for (int i = 1; i <= 1e5; i++) {
		if (!visited[i]) { dfs(i); }
	}
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  int m;
  cin>>n>>m;
  adj.resize(n, vi());
  for(int i=0,u,v;i<m;++i){
    cin>>u>>v;
    adj[u-1].PB(v-1);
    // adj[v-1].PB(u-1);
  }
  find_cycle();
  return 0;
}