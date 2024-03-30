// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef vector<int> vi;
vector<vi> adj;
vi dist;

// Forma 1: dfs cualquier a, a -> b donde b es el más lejano, luego dfs b -> c donde c es el más lejano, respuesta distancia b -> c
// Forma 2: dp, estados: distancia más lejana a una hoja, distancia más lejana un path pasando por a 
void dfs(int v, int p=0){
	for(auto u:adj[v]){
		if(u==p)continue;
		dist[u]=dist[v]+1;
		dfs(u,v);
	}
}
 
int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n;cin>>n;
	adj.assign(n+1,vi());
	dist.assign(n+1,0);
	for(int i=0,a,b;i<n-1;++i){
		cin>>a>>b;
		adj[a].PB(b);
		adj[b].PB(a);
	}
	dist[1]=0;
	dfs(1);
	int id=0,maxi=0;
	for(int i=1;i<=n;++i){
		if(maxi<dist[i]){
			maxi=dist[i];
			id=i;
		}
	}
	dist[id]=0;
	dfs(id);
	int ans=0;
	for(auto x:dist)ans=max(ans, x);
	cout<<ans<<"\n";
	return 0;
}
