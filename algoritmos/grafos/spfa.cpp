// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"
#define S second
#define F first
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = 1e9;
int n;

// Shortest Path Faster Algorithm
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
  // freopen("file.in", "r", stdin);
  // freopen("file.out", "w", stdout);
  int m;
  cin>>n>>m;
  vector<vii> adj(n);
  for(int i=0,a,b,w;i<m;++i){
    cin>>a>>b>>w;
    adj[a-1].push_back({b-1,-w});
  }
  vi dist;
  int s=0;
  bool negativeCicle=spfa(adj,dist,s);
  if(negativeCicle){
    cout<<"Hay ciclos negativos\n";
  }else{
    cout<<"No hay ciclos negativos\n";
  }
    print(dist);
  return 0;
}