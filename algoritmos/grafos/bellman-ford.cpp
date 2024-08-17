#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x+1<<" ";cout<<"\n"
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<ll> vl;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const ll INFL = 1e18;
const int maxn = 1e5;
vii adj[maxn];
int n;

// O(nm)
void bellman_ford(int s){
	vl dist(n,INFL),cycle,p(n,-1);
	dist[s]=0;
	for(int i=0;i<n;++i){
		for(int u=0;u<n;++u){
			if(dist[u]==INFL)continue;
			for(auto x:adj[u]){
				int v=x.first;
				int w=x.second;
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
			int v=x.first;
			int w=x.second;
			if(dist[i]+w>=dist[v])continue;
			s2=i;break;
		}
	}
	if(s2==-1){
		cout<<"No negative cycle\n";
		return;
	}
	for(int i=0;i<n;++i)s2=p[s2];
	cycle.push_back(s2);
	for(int v=s2;p[v]!=s2;v=p[v])cycle.push_back(p[v]);
	cycle.push_back(s2);
	reverse(all(cycle));
	print(cycle);
}
