#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"
#define sz(x) ((int) x.size())
typedef vector<int> vi;
const int maxn = 1e5+5;
int out[maxn],in[maxn];
vi adj[maxn],path;
int n,m;

void dfs(int v){
	while(!adj[v].empty()){
		int u=adj[v].back();
		adj[v].pop_back();
		dfs(u);
	}
	path.push_back(v);
}

void eulerian_path(int start, int end){ 
	for(int i=0;i<n;++i){
		if(i==start || i==end)continue;
		if(in[i]!=out[i]){
			cout<<"IMPOSSIBLE\n";
			return;
		}
	}
	if(out[start]-in[start]!=1 || in[end]-out[end]!=1){
		cout<<"IMPOSSIBLE\n";
		return;
	}
	dfs(start);
	reverse(path.begin(), path.end());
	if(sz(path)!=m+1 || path.back()!=end)cout<<"IMPOSSIBLE\n";
	else print(path);
}
