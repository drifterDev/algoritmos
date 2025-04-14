#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
vector<int> adj[maxn]; // undirected
vector<bool> vis;
vector<int> tin, low;
int timer;

void dfs(int v,int p=-1){
	vis[v]=true;
	tin[v]=low[v]=timer++;
	int children=0;
	for(int to:adj[v]){
		if(to==p)continue;
		if(vis[to])low[v]=min(low[v],tin[to]);
		else{
			dfs(to,v);
			low[v]=min(low[v], low[to]);
			if(low[to]>tin[v]); // v-to puente
			if(low[to]>=tin[v] && p!=-1); // v punto de articulación
			++children;
		}
	}
	if(p==-1 && children>1); // v punto de articulación
}

// O(n+m)
void init(int n){
	timer=0;
	vis.assign(n,false);
	tin.assign(n,-1);low.assign(n,-1);
	for(int i=0;i<n;++i){
		if(!vis[i])dfs(i);
	}
}
