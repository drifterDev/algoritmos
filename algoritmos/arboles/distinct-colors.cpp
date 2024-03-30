// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) x.size())
#define PB push_back
typedef vector<int> vi;
vector<set<int>> colors;
vector<vi> adj;
vi c,cnt;
int n;

// Usando la tecnica de small to large
void dfs(int v, int p=0){
	int ans=0,id=0;
	for(auto u:adj[v]){
		if(u==p)continue;
		dfs(u,v);
		if(ans<cnt[u]){
			ans=cnt[u];
			id=u;
		}
	}
	if(id!=0)swap(colors[v],colors[id]);
	for(auto u:adj[v]){
		if(u==p)continue;
		if(u==id)continue;
		for(auto x:colors[u]){
			colors[v].insert(x);
		}
	}
	colors[v].insert(c[v]);
	cnt[v]=sz(colors[v]);
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	c.assign(n+1,-1);
	cnt.assign(n+1,0);
	adj.assign(n+1,vi());
	colors.assign(n+1,set<int>());
	for(int i=1;i<=n;++i)cin>>c[i];
	for(int a,b,i=1;i<n;++i){
		cin>>a>>b;
		adj[a].PB(b);
		adj[b].PB(a);
	}
	dfs(1);
	for(int i=1;i<=n;++i)cout<<cnt[i]<<" ";
	cout<<"\n";
	return 0;
}