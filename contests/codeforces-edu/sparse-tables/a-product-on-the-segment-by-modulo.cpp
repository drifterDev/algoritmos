// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2025

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

struct DST {
	typedef int T;
	T mod;
	T op(T a, T b){return ((long long)a)*b%mod;}
	vector<vector<T>> pre, suf;
	T null = 1;
	int k, n;

	DST(vector<T>& a, int m) {
		mod = m;
		n = a.size();
		k = log2(n) + 2;
		pre.assign(k + 1, vector<T>(n));
		suf.assign(k + 1, vector<T>(n));
		for(int j = 0; (1 << j) <= n; ++j) {
			int mask = (1 << j) - 1;
			T nw = null; 	
			for(int i = 0; i < n; ++i) {
				nw = op(nw, a[i]);
				pre[j][i] = nw;
				if((i & mask) == mask) nw = null; 
			}
			nw = null; 
			for(int i = n - 1; i >= 0; --i) {
				nw = op(a[i], nw);
				suf[j][i] = nw;
				if((i & mask) == 0) nw = null;
			}
		}
	}
	int get(int l, int r) {
		if(l == r) return pre[0][l];
		int i = 31 - __builtin_clz(l ^ r);
		return op(pre[i][r], suf[i][l]);
	}
};

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n,p,q;
		cin>>n>>p>>q;
		vector<int> a(n);
		for(int& x:a)cin>>x;
		DST st(a,p);
		vector<int> b(q/64+2);
		for(int& x:b)cin>>x;
		int x=0;
		int l=0,r=0;
		for(int i=0;i<q;++i){
			if(i%64==0){
				l=(b[i/64]+x)%n;
				r=(b[i/64+1]+x)%n;
			}else{
				l=(l+x)%n;
				r=(r+x)%n;
			}
			if(l>r)swap(l,r);
			x=((st.get(l,r)%p)+1)%p;
		}
		cout<<x<<"\n";
	}
	return 0;
}
