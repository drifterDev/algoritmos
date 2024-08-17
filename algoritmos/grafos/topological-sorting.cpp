#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef vector<int> vi;
const int maxn = 1e5+5;
vi adj[maxn];
vi order;
vi grade;
int n,m;

// O(n+m)
void bfs(){
	queue<int> q;
	for(int i=0;i<n;i++)if(!grade[i])q.push(i);
	while(!q.empty()){
		int act=q.front();q.pop();
		order.push_back(act);
		for(int v:adj[act]){
			grade[v]--;
			if(grade[v]==0)q.push(v);
		}
	}
}

// if(order.size()<n)cout<<"-1\n";