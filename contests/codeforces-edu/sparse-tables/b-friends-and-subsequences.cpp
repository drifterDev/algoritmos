// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2025

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

struct Table{
	vector<vector<int>> st;
	int type;
	int oper(int a, int b){
		if(type)return max(a,b);
		return min(a,b);
	}
	Table(vector<int>& a, int ty){
		st.push_back(a);
		int n=a.size();
		type=ty;
		for(int i=1;(1<<i)<=n;++i){
			st.push_back(vector<int>());
			for(int j=0;j+(1<<i)-1<n;++j){
				st[i].push_back(oper(st[i-1][j], st[i-1][j+(1<<(i-1))]));
			}
		}
	}
	int get(int l, int r){
		int lg=31-__builtin_clz(r-l+1);
		return oper(st[lg][l], st[lg][r-(1<<lg)+1]);
	}
};

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n;
	cin>>n;
	vector<int> a(n),b(n);
	for(int& x:a)cin>>x;
	for(int& x:b)cin>>x;
	Table mx(a,1);
	Table mn(b,0);
	int q,l,r;
	cin>>q;
	long long ans=0;
	for(int i=0;i<n;++i){
		int l=i,r=n-1;
		while(l<=r){
			int m=l+(r-l)/2;
			if(mx.get(i,m)<mn.get(i,m))l=m+1;
			else r=m-1;
		}
		int ll=l;
		l=i,r=n-1;
		while(l<=r){
			int m=l+(r-l)/2;
			if(mx.get(i,m)<=mn.get(i,m))l=m+1;
			else r=m-1;
		}
		int rr=l;
		ans+=rr-ll;
	}
	cout<<ans<<"\n";
	return 0;
}
