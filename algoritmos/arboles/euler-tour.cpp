#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> tour;

void dfs(int v,int p=0){
	tour.push_back(v);
	for(auto u:adj[v]){
		if(u==p)continue;
		dfs(u, v);
		tour.push_back(v);
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n;cin>>n;
	adj.assign(n+1,vector<int>());
	for(int a,b,i=0;i<n-1;++i){
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	for(auto x:tour){
		cout<<x<<" ";
	}
	return 0;
}