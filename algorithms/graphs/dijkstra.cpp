#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;
vector<vll> adj;
int n;

// O((n+m)log(m))
vl dijkstra(int s){
	priority_queue<pll, vll, greater<pll>> pq;
	pq.push({0, s});
	vl dist(n, LONG_LONG_MAX); 
	dist[s]=0;
	while(!pq.empty()){
		pll act=pq.top();pq.pop();
		ll d=act.first;
		int u=act.second;
		if(d>dist[u])continue;
		for(auto v:adj[u]){
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

// O(kmlog(km))
void kShortestPaths(int s, int t, int k){
	priority_queue<pll, vll, greater<pll>> pq;
	pq.push({0, s});
	vector<int> cnt(n, 0);
	vector<ll> paths;
	while(cnt[t]<k){
		pll act=pq.top();pq.pop();
		ll d=act.first;
		int u=act.second;
		if(cnt[u]==k)continue;
		cnt[u]++;
		if(u==t)paths.push_back(d);
		for(auto v:adj[u]){
			ll w=v.second;
			int b=v.first;
			pq.push({d+w,b});
		}
	}
	for(auto x:paths)cout<<x<<" ";
	cout<<"\n";
}