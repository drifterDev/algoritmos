// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2025

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int add(int a, int b){return (a+b>=mod?a+b-mod:a+b);}
int sbt(int a, int b){return (a-b<0?a-b+mod:a-b);}
int mul(int a, int b){return ((long long)a)*b%mod;}

vector<vector<vector<int>>> suf,pre;
vector<int> ls,rs,ans;
int k;

void dnc(vector<int>& a, vector<int>& queries, int l, int r){
	if(queries.empty())return;
	if(l+1==r){
		for(auto i:queries)ans[i]=2;
		return;
	}
	vector<int> ql,qr,qs;
	int m=(l+r)/2;
	int li=r,ri=l;
	for(auto i:queries){
		if(rs[i]<m){
			ql.push_back(i);
		}else if(m<=ls[i]){
			qr.push_back(i);
		}else{
			qs.push_back(i);
			li=min(li, ls[i]);
			ri=max(ri, rs[i]);
		}
	}
	dnc(a,ql,l,m);
	dnc(a,qr,m,r);
	if(li>ri)return;
	suf.assign(m-li, vector<vector<int>>(k, vector<int>(k, 0)));
	pre.assign(ri-m+1, vector<vector<int>>(k, vector<int>(k, 0)));
	for(int ki=0,i=m-1;i>=li;--i,++ki){
		if(ki-1>=0)suf[ki]=suf[ki-1];
		suf[ki][a[i]][a[i]]=add(suf[ki][a[i]][a[i]], 1);
		if(ki==0)continue;
		for(int id=a[i];id<k;++id){
			for(int j=id;j<k;++j){
				suf[ki][a[i]][j]=add(suf[ki][a[i]][j], suf[ki-1][id][j]);
			}
		}
	}
	for(int ki=0,i=m;i<=ri;++i,++ki){
		if(ki-1>=0)pre[ki]=pre[ki-1];
		pre[ki][a[i]][a[i]]=add(pre[ki][a[i]][a[i]], 1);
		if(ki==0)continue;
		for(int id=0;id<=a[i];++id){
			for(int j=id;j<=a[i];++j){
				pre[ki][id][a[i]]=add(pre[ki][id][a[i]], pre[ki-1][id][j]);
			}
		}
	}
	for(int ki=0;ki<((int)suf.size());++ki){
		for(int i=0;i+1<k;++i){
			for(int j=0;j<k;++j){
				suf[ki][i+1][j]=add(suf[ki][i+1][j], suf[ki][i][j]);
			}
		}
	}
	for(int ki=0;ki<((int)pre.size());++ki){
		for(int i=0;i<k;++i){
			for(int j=0;j+1<k;++j){
				pre[ki][i][j+1]=add(pre[ki][i][j+1], pre[ki][i][j]);
			}
		}
	}
	for(int ki=0;ki<((int)suf.size());++ki){
		for(int j=0;j+1<k;++j){
			suf[ki][k-1][j+1]=add(suf[ki][k-1][j+1], suf[ki][k-1][j]);
		}
	}
	for(int i:qs){
		int k1=m-ls[i]-1;
		int k2=rs[i]-m;
		ans[i]=add(suf[k1][k-1][k-1],1);
		for(int j=0;j<k;++j){
			ans[i]=add(ans[i], mul(suf[k1][k-1][j], pre[k2][j][k-1]));
			ans[i]=add(ans[i], pre[k2][j][k-1]);
		}
	}
}

void solve(){
	int n;
	cin>>n>>k;
	vector<int> a(n);
	for(int& x:a){cin>>x;x--;}
	int q;
	cin>>q;
	vector<int> idx;
	ls.resize(q);
	rs.resize(q);
	ans.resize(q);
	for(int i=0;i<q;++i){
		cin>>ls[i]>>rs[i];
		ls[i]--;rs[i]--;
		idx.push_back(i);
	}
	dnc(a,idx,0,n);
	for(int x:ans)cout<<x<<"\n";
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}