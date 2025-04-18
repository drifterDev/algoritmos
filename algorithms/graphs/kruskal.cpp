#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef long long ll;

struct DSU{
	int maxSz;
	DSU(int n);
	int get(int a);
	void unite(int a, int b);
};

vector<tuple<int,int,int>> edges;

// O(m*log(n))
void kruskal(int n){
	sort(all(edges));
	DSU uf(n);
	ll ans=0;
	for(auto& [w,u,v]:edges){
		if(uf.get(u)!=uf.get(v)){
			uf.unite(u, v);
			ans+=w;
		}
	}
	if(uf.maxSz!=n)cout<<"IMPOSSIBLE\n";
	else cout<<ans<<"\n";
}
