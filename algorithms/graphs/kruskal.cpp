#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<ll> vl;
typedef pair<int, int> ii;
typedef vector<ii> vii;
vector<tuple<int,int,int>> edges;
int n,m;

struct dsu{
	ll maxSz;
	dsu(ll n);
	ll findSet(ll v);
	bool isSameSet(ll i,ll j);
	void unionSets(ll a, ll b);
};

// O(mlogn)
void kruskal(){
	sort(all(edges));
	dsu uf(n);
	ll ans=0;
	vii mst;
	for(auto e:edges){
		int w=get<0>(e);
		int u=get<0>(e);
		int v=get<0>(e);
		if(!uf.isSameSet(u, v)){
			uf.unionSets(u, v);
			ans+=w;
			mst.push_back({u, v});
		}
	}
	if(uf.maxSz!=n)cout<<"IMPOSSIBLE\n";
	else cout<<ans<<"\n";
	for(auto& e:mst)cout<<e.first+1<<" "<<e.second+1<<"\n";
}
