// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5+5;
const int maxlog = 20+5; 
vector<int> adj[maxn];
int up[maxn][maxlog];
int dep[maxn];
int n,q; 

void dfs(int v, int p=-1){
    up[v][0]=p;
	for(int u:adj[v]){
		if(u!=p){
            dep[u]=dep[v]+1;
            dfs(u, v);
        }
	}
}

void build(){
	for(int l=1;l<maxlog;++l){
		for(int i=0;i<n;++i){
			if(up[i][l-1]!=-1){
				up[i][l]=up[up[i][l-1]][l-1];
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

int dist(int a, int b){
    return dep[a]+dep[b]-2*dep[lca(a,b)];
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	memset(dep, 0, sizeof(dep)); 
	memset(up, -1, sizeof(up)); 
	cin>>n;
	for(int a,b,i=1;i<n;++i){
		cin>>a>>b;b--;a--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
    dfs(0);
	build();
	int a,b,c;
	cin>>q;
    while(q--){
		cin>>a>>b>>c;
        a--;b--;
		if(dist(a,b)<=c)cout<<b+1<<"\n";
		else{
			int lc=lca(a,b);
			int d1=dist(a,lc);
			if(d1>c){
				cout<<kth(a,c)+1<<"\n";
			}else if(d1<c){
				int d2=dist(b,lc);
				c-=d1;
				cout<<kth(b,d2-c)+1<<"\n";
			}else cout<<lc+1<<"\n";
		}
	}
	return 0;
}