#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, int> par;
const int maxn = 1e5;
vector<par> adj[maxn];
int n;

// O((n+m)log(m))
vl dijkstra(int s){
	priority_queue<par, vector<par>, greater<par>> pq;
	vl dist(n, LONG_LONG_MAX); 
	pq.push({0, s});
	dist[s]=0;
	while(!pq.empty()){
		par act=pq.top();pq.pop();
		ll d=act.first;
		int u=act.second;
		if(d>dist[u])continue;
		for(par v:adj[u]){
			ll w=v.second;
			int b=v.first;
			if(dist[u]+w<dist[b]){
				dist[b]=dist[u]+w;
				pq.push({dist[b],b});
			}
		}
	}
	return dist;
}
