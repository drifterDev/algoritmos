#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef vector<int> vi;
vector<vector<int>> adj;
vector<int> grade,order;
int n,m;

// O(n+m)
void bfs(){
	queue<int> q;
	for(int i=0;i<n;i++)if(!grade[i])q.push(i);
	while(!q.empty()){
		int act=q.front();q.pop();
		order.PB(act);
		for(int v:adj[act]){
			grade[v]--;
			if(grade[v]==0)q.push(v);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	vector<vi> adj(n);
	vi grade(n), order;
	for(int i=0,a,b;i<m;++i){
		cin>>a>>b;
		a--;b--;
		adj[a].PB(b);
		grade[b]++;
	}
	bfs();
	if(order.size()<n)cout<<"IMPOSSIBLE\n";
	else{
		for(int x:order)cout<<x+1<<" ";
		cout<<"\n";
	}
	return 0;
}