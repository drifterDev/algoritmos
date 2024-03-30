// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"
#define all(x) x.begin(), x.end()
#define PB push_back
typedef vector<int> vi;
vector<vi> adj, adj_rev;
vector<bool> used;
vi order, component;

// O(n+m)
void dfs1(int v){
	used[v]=true;
	for(auto u:adj[v])
		if(!used[u])dfs1(u);
	order.PB(v);
}

void dfs2(int v){
	used[v]=true;
	component.PB(v);
	for(auto u:adj_rev[v])
		if(!used[u])dfs2(u);
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,m;cin>>n>>m;
	adj.assign(n,vi());
	adj_rev.assign(n,vi());
	used.assign(n,false);
	for(int i=0,a,b;i<m;++i){
		cin>>a>>b;
		adj[a-1].PB(b-1);
		adj_rev[b-1].PB(a-1);
	}

	for(int i=0;i<n;++i){
		if(!used[i])dfs1(i);
	}

	used.assign(n, false);
	reverse(all(order));
	for(auto v:order){
		if(!used[v]){
			dfs2(v);
			print(component);
			component.clear();
		}
	}
	return 0;
}
