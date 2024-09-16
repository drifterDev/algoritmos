#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"
#define watch(x) cout<<#x<<"="<<x<<"\n"
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int maxn = 3e5+5;
vi adj[maxn];
int dp1[maxn];
int dp2[maxn];
int dp3[maxn];
int id[maxn];
int n,dia=0;

void dfs(int v, int p=-1){
	dp1[v]=0;
	id[v]=-1;
	for(int u:adj[v]){
		if(u==p)continue;
		dfs(u,v);
		if(dp1[u]+1>dp1[v]){
			id[v]=u;
			dp2[v]=dp1[v];
			dp1[v]=dp1[u]+1;
		}else{
			dp2[v]=max(dp2[v], dp1[u]+1);
		}
	}
}

void dfs2(int v, int p=-1, int tmp=0){
	dp3[v]=max(tmp,dp1[v]);
	dia=max(dia, dp3[v]);
	for(int u:adj[v]){
		if(u==p)continue;
		if(u==id[v])dfs2(u,v,max(tmp, dp2[v])+1);
		else dfs2(u,v,max(tmp, dp1[v])+1);
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int a,b,i=0;i<n-1;++i){
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	dfs2(1);
	for(int i=1;i<=n;++i){
		cout<<dia+(dp3[i]==dia)<<"\n";
	}
	return 0;
}
