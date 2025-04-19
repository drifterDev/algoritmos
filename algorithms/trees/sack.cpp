#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
vector<int> adj[maxn];
int ver[2*maxn]; // node at position i in euler tour
int len[maxn];	// size of the subtree 
int st[maxn]; // start time of v
int ft[maxn]; // finish time of v
int pos=0;

// O(n*log(n))
// 1) dfs0(root);
// 2) dfs1(root);

void dfs0(int v=0, int p=-1){
	len[v]=1;
	ver[pos]=v;
	st[v]=pos++;
	for(int u:adj[v]){
		if(u==p)continue;
		dfs0(u,v);
		len[v]+=len[u];
	}
	ver[pos]=v;
	ft[v]=pos++;
}

bool vis[maxn];
void ask(int v, bool add){
	if(vis[v] && !add){
		vis[v]=false;
		// delete node v  
		// ...
	}else if(!vis[v] && add){
		vis[v]=true;
		// add node v
		// ...
	}
}

void dfs1(int v=0, int p=-1, bool keep=true){
	int mx=0,id=-1;
	for(int u:adj[v]){
		if(u==p)continue;
		if(len[u]>mx){
			mx=len[u];
			id=u;
		}
	}
	for(int u:adj[v]){
		if(u!=p && u!=id)
			dfs1(u,v,0); 
	}
	if(id!=-1)dfs1(id,v,1); 
	for(int u:adj[v]){
		if(u==p || u==id)continue;
		for(int p=st[u];p<ft[u];++p)
			ask(ver[p], 1);
	}
	ask(v, 1);
	// answer queries related to subtree of v
	// ...
	if(keep)return;
	for(int p=st[v];p<ft[v];++p)
		ask(ver[p], 0);
}