// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"
#define sz(x) ((int) x.size())
#define PB push_back
#define S second
#define F first
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int maxn = 1e5+1;
const int maxm = 2e5+1;
int n,m;

// O(m)
// Un camino que pasa por todas las aristas
void euler_tour(vector<vii>& adj, vi& degree){
  vector<bool> visited(m,false);
  stack<int> s;
  vi path;
  s.push(1);
  while(!s.empty()){
    int u=s.top();
    if(degree[u]){
      while(!adj[u].empty()){
        int v=adj[u].back().F;
        int id=adj[u].back().S;
        adj[u].pop_back();
        if(!visited[id]){
          visited[id]=true;
          degree[u]--;
          degree[v]--;
          s.push(v);
          break;
        }
      }
    }else{
      path.PB(u);
      s.pop();
    }
  }

  if(sz(path)!=m+1){
    cout<<"IMPOSSIBLE\n";
    return;
  }else{
    print(path);
  }
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  // freopen("file.in", "r", stdin);
  // freopen("file.out", "w", stdout);
  cin>>n>>m;
  vector<vii> adj(n+1);
  vi degree(n+1,0);
  for(int i=0,a,b;i<m;++i){
    cin>>a>>b;
    adj[a].PB({b,i});
    adj[b].PB({a,i});
    degree[a]++;
    degree[b]++;
  }
  bool flag=true;
  for(int i=1;i<=n;++i)if(degree[i]%2)flag=false;
  if(!flag){
    cout<<"IMPOSSIBLE\n";
    return 0;
  }
  euler_tour(adj,degree);
  return 0;
}