#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x+1<<" ";cout<<"\n"
#define all(x) x.begin(), x.end()
#define PB push_back
#define S second
#define F first
typedef long long ll;
typedef vector<ll> vl;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const ll INFL = 1e18;
int n;

// O(nm)
// El camino más corto de s a todos los demás vértices
void bellman_ford(vector<vii> &adj, int s){
	vl dist(n,INFL),cycle,p(n,-1);
	dist[s]=0;
	for(int i=0;i<n;++i){
		for(int u=0;u<n;++u){
			if(dist[u]==INFL)continue;
			for(auto x:adj[u]){
				int v=x.F,w=x.S;
				if(dist[u]+w>=dist[v])continue;
				dist[v]=dist[u]+w;
				p[v]=u;
			}
		}
	}
	int s2=-1;
	for(int i=0;i<n;++i){
		if(dist[i]==INFL)continue;
		for(auto x:adj[i]){
			int v=x.F,w=x.S;
			if(dist[i]+w>=dist[v])continue;
			s2=i;
			break;
		}
	}
	if(s2==-1){
		cout<<"No negative cycle\n";
		return;
	}
	cout<<"Negative cycle\n";
	for(int i=0;i<n;++i)s2=p[s2];
	cycle.PB(s2);
	for(int v=s2;p[v]!=s2;v=p[v])cycle.PB(p[v]);
	cycle.PB(s2);
	reverse(all(cycle));
	print(cycle);
}
 
int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int m;
	cin>>n>>m;
	vector<vii> adj(n);
	int s=0;
	for(int i=0,a,b,w;i<m;++i){
		cin>>a>>b>>w;
		adj[a-1].push_back({b-1,w});
	}
	bellman_ford(adj,s);
	return 0;
}