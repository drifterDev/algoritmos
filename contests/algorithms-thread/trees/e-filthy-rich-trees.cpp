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
typedef double lf;
const lf eps = 1e-12;

typedef lf T;
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

const int maxn = 3e5+5;
const lf limit = log(1e9);
vi adj[maxn];
int times[maxn];
int sub[maxn];
lf logs[maxn];
int act=0;

void dfs(int v, int p=-1){
	times[v]=act++;
	sub[v]=0;
	for(int u:adj[v]){
		if(u==p)continue;
		dfs(u,v);
		sub[v]+=sub[u]+1;
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cout<<setprecision(10)<<fixed;
	for(int i=0;i<maxn;++i)logs[i]=log(i);
	int n;
	cin>>n;
	for(int a,b,i=0;i<n-1;++i){
		cin>>a>>b;
		a--;b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0);
	SegTree st;
	vector<T> palst(n,log(1));
	st.build(palst);
	int q;cin>>q;
	int a,b,c;
	while(q--){
		cin>>c>>a>>b;
		a--;b--;
		if(c==1)st.upd(times[a], logs[b+1]);
		else{
			T c1=st.get(times[a], times[a]+sub[a]);
			T c2=st.get(times[b], times[b]+sub[b]);
			if(limit-(c1-c2)<eps)cout<<"1000000000\n";
			else cout<<exp(c1-c2)<<"\n";
		}
	}
	return 0;
}