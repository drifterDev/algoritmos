#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"
vector<vector<int>> adj;
vector<bool> visited; 
vector<int> parent;
int cy0,cy1;

bool dfs(int v, int par){ 
	visited[v]=true;
	for(int u:adj[v]){
		if(u==par)continue;
		if(visited[u]){
			cy1=v;
			cy0=u;
			return true;
		}
		parent[u]=v;
		if(dfs(u,parent[u]))return true;
	}
	return false;
}

// O(m)
void find_cycle(int n){
	visited.assign(n, false); 
	parent.assign(n, -1);
	cy0=-1;
	for(int v=0;v<n;++v){
		if(!visited[v]){
		  if(dfs(v, parent[v]))break;
		}
	}

	if(cy0==-1){
		cout<<"IMPOSSIBLE\n";
		return;
	}

	vector<int> cycle;
	cycle.push_back(cy0);
	for(int v=cy1;v!=cy0;v=parent[v])cycle.push_back(v);
	cycle.push_back(cy0);
	print(cycle);
}
