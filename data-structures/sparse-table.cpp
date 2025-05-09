#include <bits/stdc++.h>
using namespace std;

// O(n*log(n)) build
// O(1) get
typedef long long T;
T op(T a, T b); // max, min, gcd ...
struct Table{ 
	vector<vector<T>> st;
	Table(vector<T>& v){
		int n=v.size();
		st.assign(ceil(log2(n))+3, vector<T>(n)); 
		for(int i=0;i<n;++i)st[0][i]=v[i];
		for(int j=1;(1<<j)<=n;++j){
			for(int i=0;i+(1<<(j-1))<n;++i){
				st[j][i]=op(st[j-1][i],st[j-1][i+(1<<(j-1))]);
			}
		}
	}
	T get(int l, int r){
		int j=31-__builtin_clz(r-l+1);
		return op(st[j][l], st[j][r-(1<<j)+1]);
	}
};
