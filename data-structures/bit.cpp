#include <bits/stdc++.h>
using namespace std;
typedef long long T;

// O(n) - O(log(n))
struct BIT{ // 0-indexed 
	int n;vector<T> t; 
	BIT(int _n){
		n=_n;t.assign(n+1,0);
	}
	T get(int i){
		if(i<0)return 0;
		i++;
		T ans=0;i=min(i,n);
		for(;i>=1;i-=(i&-i))ans+=t[i];
		return ans;
	}
	void upd(int i, T val){
		if(i<0)return;
		i+=1;
		for(;i<=n;i+=(i&-i))t[i]+=val;
	}
	T get(int l, int r){
		if(l>r)return 0;
		return get(r)-get(l-1);
	}
};
