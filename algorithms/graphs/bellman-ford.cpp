#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, int> par;

const int maxn = 1e5;
const ll inf = 1e18;
vector<par> adj[maxn];

// O(n*m)
bool bellman(int s, int n){
	vector<ll> dist(n,inf);
	dist[s]=0;
	for(int i=0;i<=n;++i){
		bool change=0;
		for(int u=0;u<n;++u){
			if(dist[u]==inf)continue;
			for(auto [w,v]:adj[u]){
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
