#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef long long ll;
vector<tuple<int,int,int>> edges;
int n,m;

struct dsu{
	int maxSz;
	dsu(int n);
	int get(int a);
	void unite(int a, int b);
};

// O(mlogn)
void kruskal(){
	sort(all(edges));
	dsu uf(n);
	ll ans=0;
	for(auto e:edges){
		int w=get<0>(e);
		int u=get<1>(e);
		int v=get<2>(e);
		if(uf.get(u)!=uf.get(v)){
			uf.unite(u, v);
			ans+=w;
		}
	}
	if(uf.maxSz!=n)cout<<"IMPOSSIBLE\n";
	else cout<<ans<<"\n";
}
