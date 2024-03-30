// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define S second
#define F first
typedef vector<int> vi;
typedef pair<int, int> ii;
vector<vi> adj;
vi max1,max2;

// El camino mas largo de un nodo v a cualquier otro nodo
void dfs1(int v, int p=0){
	max1[v]=0;
	for(auto u:adj[v]){
		if(u==p)continue;
		dfs1(u,v);
		max1[v]=max(max1[v], max1[u]+1);
	}
}

void dfs2(int v, int p=0){
	ii best={0,0};
	for(auto u:adj[v]){
		if(u==p)continue;
		if(max1[best.F]<=max1[u]){
			best.S=best.F;
			best.F=u;
		}else if(max1[best.S]<max1[u]){
			best.S=u;
		}
	}

	for(auto u:adj[v]){
		if(u==p)continue;
		max2[u]=max(max2[u], max2[v]+1);
		if(best.F==u){
			if(best.S!=0 && best.S!=u)max2[u]=max(max2[u], max1[best.S]+2);
		}else if(best.F!=0)max2[u]=max(max2[u], max1[best.F]+2);
		dfs2(u,v);
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n;cin>>n;
	adj.assign(n+1,vi());
	max1.assign(n+1,0);
	max2.assign(n+1,0);
	for(int i=0,a,b;i<n-1;++i){
		cin>>a>>b;
		adj[a].PB(b);
		adj[b].PB(a);
	}
	dfs1(1);
	dfs2(1);
	for(int i=1;i<=n;++i)cout<<max(max1[i], max2[i])<<" ";
	cout<<"\n";
	return 0;
}