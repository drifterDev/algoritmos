// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2025

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

struct Table{
	vector<vector<int>> st;
	Table(vector<int>& a){
		st.push_back(a);
		int n=a.size();
		for(int i=1;(1<<i)<=n;++i){
			st.push_back(vector<int>());
			for(int j=0;j+(1<<i)-1<n;++j){
				st[i].push_back(min(st[i-1][j], st[i-1][j+(1<<(i-1))]));
			}
		}
	}
	int get(int l, int r){
		int lg=31-__builtin_clz(r-l+1);
		return min(st[lg][l], st[lg][r-(1<<lg)+1]);
	}
};

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n);
		for(int& x:a)cin>>x;
		Table rmq(a);
		int q,l,r;
		cin>>q;
		while(q--){
			cin>>l>>r;
			cout<<rmq.get(l,r)<<"\n";
		}
	}
	return 0;
}
