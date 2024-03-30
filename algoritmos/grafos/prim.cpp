// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define S second
#define F first
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
int n,m;

// O(n+mlogm)
void prim(vector<vii>& edges){
	priority_queue<ii,vii,greater<ii>> pq;
	vector<bool> visited(n,false);
	ll costo=0,count=0;
	pq.push({0,0});
	while(!pq.empty()){
		ii curr=pq.top();pq.pop();
		if(visited[curr.S])continue;
		visited[curr.S]=true;
		costo+=curr.F;
		count++;
		if(count==n)break;
		for(auto& e:edges[curr.S]){
			if(!visited[e.S])pq.push(e);
		}
	}
	if(count<n)cout<<"IMPOSSIBLE\n";
	else cout<<costo<<"\n";
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	vector<vii> edges(n);
	for(int u,v,w,i=0;i<m;++i){
		cin>>u>>v>>w;
		edges[u-1].PB({w,v-1});
		edges[v-1].PB({w,u-1});
	}
	prim(edges);
	return 0;
}
