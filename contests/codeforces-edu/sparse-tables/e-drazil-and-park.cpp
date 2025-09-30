// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2025

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// sum l, sum r, best l, best r, last l, last r, ans
typedef tuple<ll, ll, ll, ll, ll, ll, ll> T;
T null = {0,0,0,0,0,0,0};
T op(T a, T b){
	if(a==null)return b;
	if(b==null)return a;
	auto [asl, asr, al, ar, alastl, alastr, ai]=a;
	auto [bsl, bsr, bl, br, blastl, blastr, bi]=b;
	T c={
		asl+bsl,
		asr+bsr,
		max(al+bsr, bl),
		max(ar, asl+br),
		alastl,
		blastr,
		max({ai, bi, al+br-alastr}),
	};
	return c;
}
struct DST {
	vector<vector<T>> pre, suf;
	int k, n;
	DST(vector<T>& a) {
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
	T get(int l, int r) {
		if(l == r) return pre[0][l];
		int i = 31 - __builtin_clz(l ^ r);
		return op(suf[i][l], pre[i][r]);
	}
};

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,q;
	cin>>n>>q;
	vector<ll> d(n),h(n);
	for(int i=0;i<n;++i){
		cin>>d[i];
		d.push_back(d[i]);
	}
	for(int i=0;i<n;++i){
		cin>>h[i];
		h.push_back(h[i]);
	}
	vector<T> palst;
	palst.push_back(null);
	for(int i=1;i<2*n;++i){
		int j=i-1;
		palst.push_back({d[j], d[i], h[i]+h[i]+d[i], h[i]+h[i]+d[j], d[j], d[i], 0});        
	}
	DST st(palst);
	int a,b;
	while(q--){
		cin>>a>>b;a--;b--;
		if(a>b)b+=n;
		int l=b+1,r=a+n-1;
		cout<<get<6>(st.get(l,r))<<"\n";
	}
	return 0;
}
