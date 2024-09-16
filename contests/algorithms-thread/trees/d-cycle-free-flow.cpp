// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9+5;
const int maxn = 3e5+5;
const int maxlog = 20+5; 
vector<pair<int,int>> adj[maxn];
int up[maxn][maxlog];
int cost[maxn][maxlog];
int dep[maxn];
int n,q,m; 

void dfs(int v, int p=-1, int c=inf){
    up[v][0]=p;
	cost[v][0]=c;
	for(auto u:adj[v]){
		if(u.first!=p){
            dep[u.first]=dep[v]+1;
            dfs(u.first, v, u.second);
        }
	}
}

void build(){
	for(int l=1;l<maxlog;++l){
		for(int i=0;i<n;++i){
			if(up[i][l-1]!=-1){
				up[i][l]=up[up[i][l-1]][l-1];
				cost[i][l]=min(cost[i][l-1], cost[up[i][l-1]][l-1]);
			}
		}
	} 
}

int kth(int node, int k){
	for(int l=maxlog-1;l>=0;--l){
		if(node!=-1 && k&(1<<l)){
			node=up[node][l];
		}
	}
	return node;
}

int lca(int a, int b){
    a=kth(a, dep[a]-min(dep[a], dep[b]));
    b=kth(b, dep[b]-min(dep[a], dep[b]));
    if(a==b)return a;
    for(int l=maxlog-1;l>=0;--l){
        if(up[a][l]!=up[b][l]){
            a=up[a][l];
            b=up[b][l];
        }
    }
    return up[a][0];
}

int kthCost(int node, int k){
	int ans=inf;
	for(int l=maxlog-1;l>=0;--l){
		if(node!=-1 && k&(1<<l)){
			ans=min(ans, cost[node][l]);
			node=up[node][l];
		}
	}
	return ans;
}

int dist(int a, int b){
    int c=lca(a,b);
	int c1=kthCost(a, dep[a]-dep[c]);
	int c2=kthCost(b, dep[b]-dep[c]);
	return min(c1, c2);
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	memset(dep, 0, sizeof(dep)); 
	memset(up, -1, sizeof(up)); 
	cin>>n>>m;
	for(int a,b,c,i=0;i<m;++i){
		cin>>a>>b>>c;b--;a--;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
    dfs(0);
	build();
	int a,b;
	cin>>q;
    while(q--){
		cin>>a>>b;
        a--;b--;
		cout<<dist(a,b)<<"\n";
	}
	return 0;
}