#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vector<bool> visited;
vector<vi> adj; // undirected
vi tin, low;
int n,timer;

void dfs(int v,int p=-1){
	visited[v]=true;
	tin[v]=low[v]=timer++;
	int children=0;
	for(int to:adj[v]){
		if(to==p)continue;
		if(visited[to])low[v]=min(low[v],tin[to]);
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
void init(){
	timer=0;
	visited.assign(n,false);
	tin.assign(n,-1);low.assign(n,-1);
	for(int i=0;i<n;++i){
		if(!visited[i])dfs(i);
	}
}
