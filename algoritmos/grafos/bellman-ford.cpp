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
const int INF = 1e9;
int n;

vi bellman_ford(vector<vii> &adj, int s){
  vi dist(n, INF);dist[s]=0;
  for(int i=0;i<n-1;++i){
    bool modified=false;
    for(int u=0;u<n;u++)
      if(dist[u]!=INF)
        for(auto e:adj[u]){
          int v=e.F,w=e.S;
          if(dist[v]<=dist[u]+w)continue; 
          dist[v]=dist[u]+w;
          modified=true;
        }
    if(!modified)break;
  }
  bool negativeCicle=false;
  for(int u=0;u<n;++u)
    if(dist[u]!=INF)
      for(auto e:adj[u]){
        int v=e.F,w=e.S;
        if(dist[v]>dist[u]+w)negativeCicle=true;
      }
  return dist;
}

//O(nm) peor caso, O(m) en promedio.
bool spfa(vector<vii>& adj,vi& d, int s){
  d.assign(n,INF);
  vi cnt(n,0);
  vector<bool> inqueue(n, false);
  queue<int> q;
  d[s]=0;
  q.push(s);
  inqueue[s]=true;
  while(!q.empty()){
    int v=q.front();q.pop();
    inqueue[v]=false;
    for(auto edge:adj[v]){
      int to=edge.F,len=edge.S;
      if(d[v]+len<d[to]){
          d[to]=d[v]+len;
          if(!inqueue[to]){
            q.push(to);
            inqueue[to]=true;
            cnt[to]++;
            if(cnt[to]>n)
              return false; //ciclo negativo
          }
      }
    }
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  int m,s;
  cin>>n>>m>>s;
  vector<vii> adj(n);
  for(int i=0,a,b,w;i<m;++i){
    cin>>a>>b>>w;
    adj[a-1].push_back({b-1,w});
    adj[b-1].push_back({a-1,w});
  }
  vi dist(n);
  bool negativeCicle=spfa(adj,dist,s-1);
  if(negativeCicle)cout<<"No hay ciclos negativos\n";
  else cout<<"Hay ciclos negativos\n";
  for(int i=0;i<n;i++)cout<<dist[i]<<" ";
  return 0;
}