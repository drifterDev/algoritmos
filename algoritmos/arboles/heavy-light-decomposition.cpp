// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef vector<int> vi;
const int maxn=2e5+5;
const int maxlog=19;
const int maxdist=(1<<maxlog);
ll st[maxdist], id[maxn], tp[maxn];
ll nodes[maxn], p[maxn], depth[maxn];
ll nums[maxn];
vi adj[maxn];
int n,q;

ll op(ll a, ll b){
  return max(a,b);
}

void update(int idx, int val){
	st[idx+=n]=val;
	for(idx/=2;idx;idx/=2)st[idx]=op(st[2*idx],st[2*idx+1]);
}

ll query(int lo, int hi){
	ll ra=0,rb=0;
	for(lo+=n,hi+=n+1;lo<hi;lo/=2,hi/=2){
		if(lo&1)ra=op(ra, st[lo++]);
		if(hi&1)rb=op(st[--hi], rb);
	}
	return op(ra, rb);
}

int dfs(int v, int par=1){
	nodes[v]=1;
	p[v]=par;
	for(int u:adj[v]){
		if(u==par)continue;
		depth[u]=depth[v]+1;
		p[u]=v;
		nodes[v]+=dfs(u, v);
	}
	return nodes[v];
}

int ct=1;

void dfs_hld(int v, int par=1, int top=1){
	id[v]=ct++;
	tp[v]=top;
	update(id[v], nums[v]);
	int hv=-1,h_sz=-1;
	for (int u:adj[v]){
		if(u==par)continue;
		if(nodes[u]>h_sz){
			h_sz=nodes[u];
			hv=u;
		}
	}
	if(hv==-1)return;
	dfs_hld(hv,v,top);
	for(int u:adj[v]){
		if(u==par || u==hv)continue;
		dfs_hld(u, v, u);
	}
}

// O(log(n)**2)
ll path(int x, int y){
	ll ret=0;
	while(tp[x]!=tp[y]){
		if(depth[tp[x]]<depth[tp[y]])swap(x, y);
		ret=op(ret, query(id[tp[x]], id[x]));
		x=p[tp[x]];
	}
	if(depth[x]>depth[y])swap(x, y);
	ret=op(ret, query(id[x], id[y]));
	return ret;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>q;
	for(int i=1;i<=n;++i)cin>>nums[i];
	for(int i=2,a,b;i<=n;++i){
    cin>>a>>b;
		adj[a].PB(b);
		adj[b].PB(a);
	}
	dfs(1);
	dfs_hld(1);
	int op,a,c;
	ll b;
	while(q--){
		cin>>op>>a;
		if(op==1){
			// update
			cin>>b;
			nums[a]=b;
			update(id[a], nums[a]);
		}else{
			// query
			cin>>c;
			cout<<path(c,a)<<" ";
		}
	}
  	return 0;
}