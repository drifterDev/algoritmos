#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
map<int, int> mp;
vector<vector<int>> adj;
vector<int> tour,depth,palst;

struct SegTree{
	int size;
	vector<ii> vals;
	ii null={INT_MAX,-1};

	ii oper(ii a, ii b){
        return min(a,b);
    }

	void build(vector<int>& a, int x, int lx, int rx){
		if(rx-lx==1){
			if(lx<(int)a.size()){
				vals[x]={a[lx], lx};
			}
			return;
		}
		int m=(lx+rx)/2;
		build(a, 2*x+1, lx, m);
		build(a, 2*x+2, m, rx);
		vals[x]=oper(vals[2*x+1], vals[2*x+2]);
	}

	void build(vector<int>& a,int n){
        size=1;
		while(size<n)size*=2;
		vals.resize(2*size);
		build(a, 0, 0, size);
	}

	ii get(int l, int r, int x, int lx, int rx){
		if(lx>=r || l>=rx)return null;
		if(lx>=l && rx<=r)return vals[x];
		int m=(lx+rx)/2;
		ii v1=get(l,r,2*x+1,lx,m);
		ii v2=get(l,r,2*x+2,m,rx);
		return oper(v1,v2);
	}

	ii get(int l, int r){
		return get(l,r+1,0,0,size);
	}
};

void dfs(int v,int p=0){
	tour.push_back(v);
	palst.push_back(depth[v]);
	mp[v]=tour.size()-1;
	for(auto u:adj[v]){
		if(u==p)continue;
		depth[u]=depth[v]+1;
		dfs(u, v);
		tour.push_back(v);
		palst.push_back(depth[v]);
	}
}

void lca(int a, int b, SegTree& st){
	int l=mp[a],r=mp[b];
	if(l>r)swap(l,r);
	cout<<tour[st.get(l,r).second]<<"\n"; 
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,q;cin>>n>>q;
	adj.assign(n+1,vector<int>());
	depth.assign(n+1, 1);
	for(int a,i=2;i<=n;++i){
		cin>>a;
		adj[a].push_back(i);
		adj[i].push_back(a);
	}
	dfs(1);
	SegTree st;
	st.build(palst, tour.size());
	int a,b;
	while(q--){
		cin>>a>>b;
		lca(a,b,st);
	}
	return 0;
}
