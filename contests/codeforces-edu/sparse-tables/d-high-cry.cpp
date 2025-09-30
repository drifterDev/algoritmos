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
		return a|b;
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
	vector<int> a(n),b;
	for(int& x:a){
		cin>>x;
		b.push_back(x);
	}
	Table tmx(a,1);
	Table tor(b,0);
	int q,l,r;
	cin>>q;
	long long ans=0;
	for(int i=0;i<n;++i){
		int j=i;
		while(j<n){
			int act=tor.get(i,j);
			int l=j,r=n-1;
			while(l<=r){
				int m=l+(r-l)/2;
				if(tor.get(i,m)==act)l=m+1;
				else r=m-1;
			}
			int j2=l;
			l=j,r=j2-1;
			while(l<=r){
				int m=l+(r-l)/2;
				if(tmx.get(i,m)<act)l=m+1;
				else r=m-1;
			}
			ans+=l-j;
			j=j2;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
