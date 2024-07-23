#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+5;
const int maxq = 1e4+5;
const int maxlog = 20+5; 
int ri[maxn],li[maxn],id[maxn*2];
vector<int> adj[maxn];
int up[maxn][maxlog];
int dep[maxn];
int n,q,pos=0; 

void dfs(int v=0, int p=-1){
	id[pos]=v;
	ri[v]=pos++;
	up[v][0]=p;
	for(int u:adj[v]){
		if(u==p)continue; 
		dep[u]=dep[v]+1;
		dfs(u,v);
	}
	id[pos]=v;
	li[v]=pos++;
}

void build(){
	for(int l=1;l<maxlog;++l){
		for(int i=0;i<n;++i){
			if(up[i][l-1]!=-1){
				up[i][l]=up[up[i][l-1]][l-1];
			}
		}
	} 
}

int kth(int node, int k){
	for(int l=maxlog-1;l>=0;--l){
		if(node!=-1 && k&(1<<l)){
			node=up[node][l];
		}
	}
	return node;
}

int lca(int a, int b){
    a=kth(a, dep[a]-min(dep[a], dep[b]));
    b=kth(b, dep[b]-min(dep[a], dep[b]));
    if(a==b)return a;
    for(int l=maxlog-1;l>=0;--l){
        if(up[a][l]!=up[b][l]){
            a=up[a][l];
            b=up[b][l];
        }
    }
    return up[a][0];
}

bool vis[maxn];
ll ans=0;

void add(int v, bool left);
void remove(int v, bool left);
void ask(int v, bool left){
	if(!vis[v])add(v, left);
	else remove(v, left);
	vis[v]=!vis[v];
}

int sqrtn;
struct query {
  int l, r, id;
  bool operator < (const query &x) const {
    if(l/sqrtn==x.l/sqrtn) return r<x.r;
    return l/sqrtn<x.l/sqrtn;
  }
};

query queries[maxq];
ll res[maxq];

void solve(){
	int l=0,r=-1;
	for(int i=0;i<q;++i){
		int L=queries[i].l,R=queries[i].r;
		if(R<l){
			while(l>L)ask(id[--l], true);
			while(l<L)ask(id[l++], true);
			while(r<R)ask(id[++r], false);
			while(r>R)ask(id[r--], false);
		}else{
			while(r<R)ask(id[++r], false);
			while(r>R)ask(id[r--], false);
			while(l>L)ask(id[--l], true);
			while(l<L)ask(id[l++], true);
		}
		int a=id[l],b=id[r],c=lca(a,b);
        // if(c!=b && c!=a)ask(c);
		res[queries[i].id]=ans;
		// if(c!=b && c!=a)ask(c);
	}
}

void reset(){
	pos=0;
	sqrtn=(int)ceil(sqrt(n));
	memset(up, -1, sizeof(up));
	memset(dep, 0, sizeof(dep));
	memset(vis, 0, sizeof(vis));
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>q;
	reset();
	for(int a,b,i=0;i<n-1;++i){
		cin>>a>>b;a--;b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs();
	build();
	for(int u,v,i=0;i<q;++i){
		cin>>u>>v;u--;v--;
		if(ri[u]>ri[v])swap(u,v);
		int lc=lca(u,v);
		if(lc==u)queries[i].l=ri[u],queries[i].r=ri[v];
		else queries[i].l=li[u],queries[i].r=ri[v];
		queries[i].id=i;
	}
	sort(queries, queries+q);
	solve();
	for(int i=0;i<q;++i)cout<<res[i]<<"\n";
	return 0;
}
