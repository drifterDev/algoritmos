// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
const ll INFL = 1e18;

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  int n;cin>>n;
  vector<vl> adj(n, vl(n,INFL)); // INF si no existe esa arista
  for(int k=0;k<n;++k){
    for(int i=0;i<n;++i){
      for(int j=0;j<n;++j){
        if(adj[i][k]<INFL && adj[k][j]<INFL)adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]); 
      }
    }
  }
  return 0;
}