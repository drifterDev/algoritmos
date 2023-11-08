// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
#define PB push_back
typedef vector<string> vs;
typedef vector<int> vi;
int n,m;

void bfs(vector<vi>& adj, vi& grade, vi& order){
  queue<int> q;
  for(int i=0;i<n;i++)if(!grade[i])q.push(i);
  while(!q.empty()){
    int act=q.front();q.pop();
    order.push_back(act);
    for(int v:adj[act]){
      grade[v]--;
      if(grade[v]==0)q.push(v);
    }
  }
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
cin>>n>>m;
vector<vi> adj(n);
vi grade(n), order;
vs vertices(n);
map<string, int> idx;
for(int i=0;i<n;++i){
  cin>>vertices[i];
  idx[vertices[i]]=i;
}
string tmp1,tmp2;
for(int i=0;i<m;++i){
  cin>>tmp1>>tmp2;
  adj[idx[tmp1]].PB(idx[tmp2]);
  grade[idx[tmp2]]++;
}
bfs(adj,grade,order);
for(int x:order)cout<<vertices[x]<<" ";
cout<<"\n";
return 0;
}