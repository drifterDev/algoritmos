#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int maxn = 1e5;
const int INF = 1e9;
int dist[maxn];
vii adj[maxn];
int n;

// Shortest Path Faster Algorithm
//O(nm) peor caso, O(m) en promedio.
bool spfa(int s){
	vi cnt(n,0);
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
			int w=x.second;
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

// adj[a].push_back({b,-w});