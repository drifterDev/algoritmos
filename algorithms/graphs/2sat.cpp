#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

// O(n+m)
// l=(x1 or y1) and (x2 or y2) and ... and (xn or yn)
struct sat2 {
	int n;
	vector<vector<vi>> g;
	vector<bool> vis, val;
	vi comp;
	stack<int> st;
	
	sat2(int n):n(n),g(2, vector<vi>(2*n)),vis(2*n),val(2*n),comp(2*n){}
	
	int neg(int x){return 2*n-x-1;}
	void make_true(int u){add_edge(neg(u), u);}
	void make_false(int u){make_true(neg(u));}
	void add_or(int u, int v){implication(neg(u),v);}
	void diff(int u, int v){eq(u, neg(v));}
	void eq(int u, int v){
		implication(u, v);
		implication(v, u);
	}
	void implication(int u,int v){
		add_edge(u, v);
		add_edge(neg(v),neg(u));
	}
	
	void add_edge(int u, int v){
		g[0][u].push_back(v);
		g[1][v].push_back(u);
	}
	
	void dfs(int id, int u, int t=0){
		vis[u]=true;
		for(auto &v:g[id][u])
			if(!vis[v])dfs(id, v, t);
		if(id)comp[u]=t;
		else st.push(u);
	}
	
	void kosaraju() {
		for(int u=0;u<n;++u){
			if(!vis[u])dfs(0, u);
			if(!vis[neg(u)])dfs(0, neg(u));
		}
		vis.assign(2*n, false);
		int t=0;
		while(!st.empty()){
			int u=st.top();st.pop();
			if(!vis[u])dfs(1, u, t++);
		}
	}
	
	bool check(){
		kosaraju();
		for(int i=0;i<n;++i){
			if(comp[i]==comp[neg(i)])return false;
			val[i]=comp[i]>comp[neg(i)];
		}
		return true;
	}
};

int main(){
	int m,n;cin>>m>>n;
	sat2 s(n);
	char c1,c2;
	for(int a,b,i=0;i<m;++i){
		cin>>c1>>a>>c2>>b;
		a--;b--;
		if(c1=='-')a=s.neg(a);
		if(c2=='-')b=s.neg(b);
		s.add_or(a,b);
	}
	if(s.check()){
		for(int i=0;i<n;++i)cout<<(s.val[i]?'+':'-')<<" ";
		cout<<"\n";
	}else cout<<"IMPOSSIBLE\n";
	return 0;
}