// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vi par,sz;

int find(int x){
	if(par[x]!=x)par[x]=find(par[x]);
	return par[x];
}

void Union(int u, int v){
	int x=find(u);
	int y=find(v);
	if(x==y)return;
	if(sz[x]>sz[y])par[y]=x;
	else if(sz[x]<sz[y])par[x]=y;
	else{
		par[x]=y;
		sz[y]++;
	}
}

void findSpanningTree(vi deg,int n,int m,vector<vi> g){
	par.resize(n+1);
	sz.resize(n+1);
	for(int i=1;i<=n;i++)par[i]=i;
	int max=1;
	for(int i=2;i<=n;i++)if(deg[i]>deg[max])max=i;
	for(int v:g[max]) {
		cout<<max<<" "<<v<<"\n";
		Union(max, v);
	}
	for(int u=1;u<=n;u++){
		for(int v:g[u]){
			int x=find(u);
			int y=find(v);
			if(x==y)continue;
			Union(x,y);
			cout<<u<<" "<<v<<"\n";
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,act,act2;cin>>n>>m;
	vector<vector<int>> g(n+1);
	vector<int> deg(n+1);
	for(int i=0;i<m;i++){
		cin>>act>>act2;
		g[act].push_back(act2);
		g[act2].push_back(act);
		deg[act]++;deg[act2]++;
	}	
	findSpanningTree(deg, n, m, g);
	return 0;
}