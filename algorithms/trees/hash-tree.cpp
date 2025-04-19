#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef pair<int, int> ii;
typedef long long ll;

const int MOD=1e9+97;
const int P[2]={998244353,1000000007};
const int Q[2]={1000000033,1000000021};
const int R[2]={123456789,987654321};

int add(int a, int b){return a+b>=MOD?a+b-MOD:a+b;}
int mul(int a, int b){return ll(a)*b%MOD;} 
int binpow(int a, int b){  
	int res=1;a%=MOD;
	while(b>0){
		if(b&1)res=mul(res,a);
		a=mul(a,a);
		b>>=1;
	}
	return res%MOD;
}

// O(n), 1-indexed
struct Tree{ 
	vector<vector<int>> g;
	int n;

	Tree(int _n):n(_n){g.resize(n+1);}
	void add_edge(int u, int v){
		g[u].push_back(v);
		g[v].push_back(u);
	}

	ii hash(int u, int pre=0){
		vector<vector<int>> nw(2,vector<int>());
		for(int v:g[u])
			if(v!=pre){
				ii tmp=hash(v,u);
				nw[0].push_back(tmp.first);
				nw[1].push_back(tmp.second);
			}
		ii ans={0,0};
		for(int i=0;i<2;++i){
			int& tmp=(i?ans.second:ans.first);
			for(int x:nw[i])tmp=add(tmp, binpow(P[i], x));
			tmp=add(mul(tmp,Q[i]),R[i]);
		}
		return ans;
	}

	// Isomorphism
	bool iso(Tree& t){
		vector<int> a=get_centers();
		vector<int> b=t.get_centers();
		for(int x:a)for(int y:b)if(hash(x)==t.hash(y))return 1;
		return 0;
	}

	vector<int> get_centers(){
		auto du=bfs(1);
		int v=max_element(all(du))-du.begin();
		auto dv=bfs(v);
		int u=max_element(all(dv))-dv.begin();
		du=bfs(u);
		vector<int> ans;
		for(int i=1;i<=n;++i){
			if(du[i]+dv[i]==du[v] && du[i]>=du[v]/2 && dv[i]>=du[v]/2){
				ans.push_back(i);
			}
		}
		return ans;
	}

	vector<int> bfs(int s){
		queue<int> q;
		vector<int> d(n+1, n*2);
		d[0]=-1;
		q.push(s);
		d[s]=0;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int v:g[u])
				if(d[u]+1<d[v]){
					d[v]=d[u]+1;
					q.push(v);
				}
		}
		return d;
	}
};
