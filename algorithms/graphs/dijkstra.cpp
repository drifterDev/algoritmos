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
	vl dist(n, LLONG_MAX); 
	pq.push({0, s});
	dist[s]=0;
	while(!pq.empty()){
		auto [d,u]=pq.top();pq.pop();
		if(d>dist[u])continue;
		for(auto [b,w]:adj[u]){
			if(dist[u]+w<dist[b]){
				dist[b]=dist[u]+w;
				pq.push({dist[b],b});
			}
		}
	}
	return dist;
}
