// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) x.size())
#define PB push_back
#define S second
#define F first
typedef vector<int> vi;
typedef pair<int, int> ii;
ii nullValue={INT_MAX,-1};
map<int, int> mp;
vector<vi> adj;
vi tour,depth,palst;

struct NodeST{
	NodeST *left,*right;
	int l,r;ii value;
	NodeST(vi &v,int l,int r):l(l),r(r){
		int m=(l+r)>>1;
		if(l!=r){
			left=new NodeST(v, l, m);
			right=new NodeST(v, m+1, r);
			value=opt(left->value, right->value);
		}else value={v[l],l};
	}
	
	ii opt(ii leftValue, ii rightValue){
		return min(leftValue, rightValue);
	}
	
	ii get(int i, int j){
		if(l>=i && r<=j)return value;
		if(l>j || r<i)return nullValue;
		return opt(left->get(i,j),right->get(i,j));
	}
};

void dfs(int v,int p=0){
	tour.PB(v);
	palst.PB(depth[v]);
	mp[v]=sz(tour)-1;
	for(auto u:adj[v]){
		if(u==p)continue;
		depth[u]=depth[v]+1;
		dfs(u, v);
		tour.PB(v);
		palst.PB(depth[v]);
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,q;cin>>n>>q;
	adj.assign(n+1,vi());
	depth.assign(n+1, 1);
	for(int a,i=2;i<=n;++i){
		cin>>a;
		adj[a].PB(i);
		adj[i].PB(a);
	}
	dfs(1);
	NodeST st(palst, 0, sz(tour)-1);
	int a,b;
	cin>>a>>b;
	int l=mp[a],r=mp[b];
	if(l>r)swap(l,r);
	cout<<tour[st.get(l,r).S]<<"\n";
	return 0;
}
