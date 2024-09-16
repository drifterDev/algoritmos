// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"
#define watch(x) cout<<#x<<"="<<x<<"\n"
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

typedef long long T;
struct SegTree{
	int n;vector<T> v;
	T null=0;
	T op(T a, T b){return a+b;}
	void build(int _n){n=_n;v.assign(2*_n,null);}
	void build(vector<T>& a){
		n=sz(a);v.assign(2*n, null);
		for(int i=0;i<n;i++)v[n+i]=a[i];
		for(int i=n-1;i>=1;--i)v[i]=op(v[i<<1],v[i<<1|1]);
	}

	void upd(int k, T nv){for(v[k+=n]=nv;k>1;k>>= 1)v[k>>1]=op(v[k], v[k^1]);}
	T get(int l, int r){
		T vl=null,vr=null;
		for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
			if(l&1)vl=op(vl,v[l++]);
			if(r&1)vr=op(v[--r],vr);
		}
		return op(vl, vr);
	}
};

vector<vector<int>> adj;
vector<int> times;
vector<int> sub;
vector<int> dep;
int act=0;

void dfs(int v, int p=-1){
	times[v]=act++;
	sub[v]=0;
	for(int u:adj[v]){
		if(u==p)continue;
		dep[u]=dep[v]+1;
		dfs(u,v);
		sub[v]+=sub[u]+1;
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int t;cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		act=0;
		adj.assign(n,vi());
		times.assign(n,0);
		sub.assign(n,0);
		dep.assign(n,0);
		for(int a,b,i=0;i<n-1;++i){
			cin>>a>>b;a--;b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		dfs(0);
		vl palst(n,0);
		SegTree st;
		st.build(palst);
		int a,b,c;
		while(q--){
			cin>>a>>b>>c;
			a--;b--;
			if(c==0){
				if(dep[a]<dep[b])swap(a,b);
				cout<<abs(st.get(times[a], times[a]+sub[a]))<<"\n";
			}else{
				palst[a]+=c;
				st.upd(times[a], palst[a]);
				palst[b]-=c;
				st.upd(times[b], palst[b]);
			}
		}
	}
	return 0;
}