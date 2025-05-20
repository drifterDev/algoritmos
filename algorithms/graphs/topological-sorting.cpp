#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

const int maxn = 1e5+5;
vi adj[maxn],order;
int grade[maxn];

// O(n+m)
bool bfs(int n){
	queue<int> q;
	for(int i=0;i<n;i++)if(!grade[i])q.push(i);
	while(!q.empty()){
		int u=q.front();q.pop();
		order.push_back(u);
		for(int v:adj[u]){
			grade[v]--;
			if(grade[v]==0)q.push(v);
		}
	}
	return order.size()==n;
}
