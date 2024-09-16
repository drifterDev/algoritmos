#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"
#define sz(x) ((int) x.size())
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int maxn = 1e5+5;
const int maxm = 2e5+5;
int degree[maxn];
bool vis[maxm];
int out[maxn];
int in[maxn];
vii adj2[maxn];
vi adj[maxn];
vi path;
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
	for(int i=1;i<=n;++i){
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

// undirected
void dfs(int v){
	while(!adj2[v].empty()){
		ii x=adj2[v].back();
		adj2[v].pop_back();
		if(vis[x.second])continue;
		vis[x.second]=true;
		dfs(x.first);
	}
	path.push_back(v);
}

void eulerian_path(){
	for(int i=1;i<=n;++i){
		if(degree[i]%2!=0){
			cout<<"IMPOSSIBLE\n";
			return;
		}
	}
	dfs(1);
	if(sz(path)!=m+1)cout<<"IMPOSSIBLE\n";
	else{
		print(path);
	}
}
