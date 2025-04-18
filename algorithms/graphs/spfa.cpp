#include <bits/stdc++.h>
using namespace std;
typedef pair<ll, int> par;
typedef long long ll;

const int maxn = 1e5+5;
const ll inf = 1e18;
vector<par> adj[maxn];

// Shortest Path Faster Algorithm
// worst case O(n*m), average O(m)
bool spfa(int s, int n){
	vector<bool> inqueue(n, false);
	vector<ll> dist(n, inf);
	vector<int> cnt(n,0);
	queue<int> q;
	dist[s]=0;
	q.push(s);
	inqueue[s]=true;
	while(!q.empty()){
		int v=q.front();q.pop();
		inqueue[v]=false;
		for(auto [w,u]:adj[v]){
			if(dist[v]+w<dist[u]){
				dist[u]=dist[v]+w;
				if(!inqueue[u]){
					q.push(u);
					inqueue[u]=true;
					cnt[u]++;
					if(cnt[u]>n)return true; // negative cycle
				}
			}
		}
	}
	return false;
}
