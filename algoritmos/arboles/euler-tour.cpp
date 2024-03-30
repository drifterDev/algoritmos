// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"
#define PB push_back
typedef vector<int> vi;
vector<vi> adj;
vi tour;

void dfs(int v,int p=0){
	tour.PB(v);
	for(auto u:adj[v]){
		if(u==p)continue;
		dfs(u, v);
		tour.PB(v);
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n;cin>>n;
	adj.assign(n+1,vi());
	for(int a,b,i=0;i<n-1;++i){
		cin>>a>>b;
		adj[a].PB(b);
		adj[b].PB(a);
	}
	dfs(1);
	print(tour);
	return 0;
}