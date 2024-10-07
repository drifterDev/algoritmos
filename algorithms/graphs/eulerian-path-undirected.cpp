#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"
#define sz(x) ((int) x.size())
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int maxn = 1e5+5, maxm = 2e5+5;
int degree[maxn],n,m;
bool vis[maxm];
vii adj[maxn];
vi path;

void dfs(int v){
	while(!adj[v].empty()){
		ii x=adj[v].back();
		adj[v].pop_back();
		if(vis[x.second])continue;
		vis[x.second]=true;
		dfs(x.first);
	}
	path.push_back(v);
}

void eulerian_path(int start){ // cycle
	for(int i=1;i<=n;++i){
		if(degree[i]%2!=0){
			cout<<"IMPOSSIBLE\n";
			return;
		}
	}
	dfs(start);
	if(sz(path)!=m+1)cout<<"IMPOSSIBLE\n";
	else print(path);
}
