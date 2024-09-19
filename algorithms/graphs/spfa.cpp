#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const int maxn = 1e5+5;
const ll INF = 1e18;
ll dist[maxn];
vector<pair<int,ll>> adj[maxn];
int n;

// Shortest Path Faster Algorithm
//O(nm) peor caso, O(m) en promedio.
bool spfa(int s){
	vi cnt(n,0);
    for(int i=0;i<n;++i)dist[i]=INF;
	vector<bool> inqueue(n, false);
	queue<int> q;
	dist[s]=0;
	q.push(s);
	inqueue[s]=true;
	while(!q.empty()){
		int v=q.front();q.pop();
		inqueue[v]=false;
		for(auto x:adj[v]){
			int u=x.first;
			ll w=x.second;
			if(dist[v]+w<dist[u]){
				dist[u]=dist[v]+w;
				if(!inqueue[u]){
					q.push(u);
					inqueue[u]=true;
					cnt[u]++;
					if(cnt[u]>n)return false; //ciclo negativo
				}
			}
		}
	}
	return true;
}
