#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int maxn = 1e5+5;
vi adj_rev[maxn],adj[maxn];
bool used[maxn];
vi order,comp;
int n,m;

// O(n+m)
void dfs1(int v){
	used[v]=true;
	for(int u:adj[v])
		if(!used[u])dfs1(u);
	order.push_back(v);
}

void dfs2(int v){
	used[v]=true;
	comp.push_back(v);
	for(int u:adj_rev[v])
		if(!used[u])dfs2(u);
}

void init(){
	for(int i=0;i<n;++i)if(!used[i])dfs1(i);
	for(int i=0;i<n;++i)used[i]=false;
	reverse(order.begin(), order.end());
	for(int v:order){
		if(!used[v]){
			dfs2(v);
			// comp
			comp.clear();
		}
	}
}

// adj[a].push_back(b);
// adj_rev[b].push_back(a);