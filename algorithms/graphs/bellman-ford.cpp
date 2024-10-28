#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const ll INFL = 1e18;
const int maxn = 1e5;
vector<ii> adj[maxn];
int n;

// O(nm)
bool bellman(int s){
	vector<ll> dist(n,INFL);
	dist[s]=0;
	for(int i=0;i<=n;++i){
		bool change=0;
		for(int u=0;u<n;++u){
			if(dist[u]==INFL)continue;
			for(auto& [v,w]:adj[u]){
				if(dist[u]+w>=dist[v])continue;
				if(i==n)return true;
				dist[v]=dist[u]+w;
				change=1;
			}
		}
		if(!change)break;
	}
	return false;
}
