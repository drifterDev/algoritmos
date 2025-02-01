// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2025

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
typedef pair<int, int> ii;
typedef long long ll;

struct DSU {
	vector<int> p,size,h;
	int sets;
	void build(int n){
		sets=n;
		p.assign(n,0);
		size.assign(n,1);
		for(int i=0;i<n;++i)p[i]=i;
	}
	int get(int a){return (a==p[a]?a:get(p[a]));} 
	void unite(int a, int b){
		a=get(a);b=get(b);
		if(a==b)return;
		if(size[a]>size[b])swap(a,b);
		h.push_back(a);
		size[b]+=size[a];
		p[a]=b;sets--;
	}
	void rollback(int s){
		while(sz(h)>s){
			int a=h.back();
			h.pop_back();
			size[p[a]]-=size[a];
			p[a]=a;sets++;
		}
	}
};

int s,n,m;
struct query {int l,r,idx;};
bool cmp(query& a, query& b){
	int x=a.l/s;
	if(a.l/s!=b.l/s)return a.l/s<b.l/s;
	return a.r<b.r;
}

vector<query> queries;
vector<int> ans;
DSU uf;

const int maxn = 5e4+5;
ii edges[maxn];

bool cmp2(int i, int j){
	auto [l1,r1,_]=queries[i];
	auto [l2,r2,_2]=queries[j];
	return l1>l2;
}

void add(int i){
	uf.unite(edges[i].first, edges[i].second);
}

void solve(){
	s=ceil(sqrt(m));
	sort(all(queries), cmp);
	ans.assign(sz(queries),0);
    vector<vector<vector<int>>> q(s, vector<vector<int>>(m, vector<int>()));
	uf.build(n);
	for(int i=0;i<sz(queries);++i){
		auto [li,ri,id]=queries[i];
        if(li/s==ri/s){
			for(int j=li;j<=ri;++j)add(j);
			ans[id]=uf.sets;
			uf.rollback(0);
		}else{
			q[li/s][ri].push_back(i);
		}
	}
	for(int i=0;i<s;++i){
		for(int r=(1+i)*s;r<m;++r){
			sort(all(q[i][r]), cmp2);
			add(r);
			int k=sz(uf.h),l=(1+i)*s;
			for(int j:q[i][r]){
				auto [li,ri,id]=queries[j];
				while(li<l)add(--l);
				ans[id]=uf.sets;
			}
			uf.rollback(k);
		}
		uf.rollback(0);
	}
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0,a,b;i<m;++i){
		cin>>a>>b;a--;b--;
		edges[i]={a,b};
	}
    int q,l,r;
	cin>>q;
	for(int i=0;i<q;++i){
		cin>>l>>r;l--;r--;
		queries.push_back({l,r,i});
	}
	solve();
	for(int x:ans)cout<<x<<"\n";
    return 0;
}
