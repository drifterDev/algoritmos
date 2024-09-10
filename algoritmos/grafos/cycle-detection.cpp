#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int cycle_start, cycle_end,n;
vector<vi> adj;
vi parent;

vector<bool> visited; // No dirigidos 
vi color; // Dirigidos

// Dirigidos
bool dfs(int v){
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

// No dirigidos
bool dfs(int v, int par){ 
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
	color.assign(n, 0); // Dirigidos
	visited.assign(n, false); // No dirigidos
	parent.assign(n, -1);
	cycle_start=-1;
	for(int v=0;v<n;++v){
		// Dirigidos
		if(color[v]==0){
			if(dfs(v))break;
		}
		// No dirigidos
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
		reverse(cycle.begin(),cycle.end()); // Dirigidos
		cout<<cycle.size()<<"\n";
		for(int v:cycle)cout<<v+1<<" ";
		cout<<"\n";
	}
}
