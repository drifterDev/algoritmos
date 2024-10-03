#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int cycle_start, cycle_end,n;
vector<vi> adj;
vi parent;

// undirected(0) - directed(1)
vector<bool> visited; // 0 
vi color; // 1

bool dfs(int v){ // 1
	color[v]=1;
	for(int u:adj[v]){
		if(color[u]==0){
			parent[u]=v;
			if(dfs(u))return true;
		}else if(color[u]==1){
			cycle_end=v;
			cycle_start=u;
			return true;
		}
	}
	color[v]=2;
	return false;
}

bool dfs(int v, int par){ // 0
	visited[v]=true;
	for(int u:adj[v]){
		if(u==par)continue;
		if(visited[u]){
			cycle_end=v;
			cycle_start=u;
			return true;
		}
		parent[u]=v;
		if(dfs(u,parent[u]))return true;
	}
	return false;
}

// O(m)
void find_cycle(){
	color.assign(n, 0); // 1
	visited.assign(n, false); // 0
	parent.assign(n, -1);
	cycle_start=-1;
	for(int v=0;v<n;++v){
		// 1
		if(color[v]==0){
			if(dfs(v))break;
		}
		// 0
		// if(!visited[v]){
		//   if(dfs(v, parent[v]))break;
		// }
	}

	if(cycle_start==-1)cout<<"IMPOSSIBLE\n";
	else{
		vi cycle;
		cycle.push_back(cycle_start);
		for(int v=cycle_end;v!=cycle_start;v=parent[v])cycle.push_back(v);
		cycle.push_back(cycle_start);
		reverse(cycle.begin(),cycle.end()); // 1
		cout<<cycle.size()<<"\n";
		for(int v:cycle)cout<<v+1<<" ";
		cout<<"\n";
	}
}
