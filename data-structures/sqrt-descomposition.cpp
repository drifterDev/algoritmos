#include <bits/stdc++.h>
using namespace std;

typedef long long T;
struct Sqrt {
	int sqrtn;
	vector<T> nums,blocks;
	void build(vector<T>& arr, int n){
		sqrtn=(int)ceil(sqrt(n));nums=arr;
        blocks.assign(sqrtn, 0);
		for(int i=0;i<n;++i){
			blocks[i/sqrtn]+=nums[i];
		}
	}

	void set(int x, int v){
		blocks[x/sqrtn]-=nums[x];
		nums[x]=v;
		blocks[x/sqrtn]+=nums[x];
	}

	T get(int r){
		T res=0;
		for(int i=0;i<r/sqrtn;++i){res+=blocks[i];}
		for(int i=(r/sqrtn)*sqrtn;i<r;++i){res+=nums[i];}
		return res;
	}

    T get(int l, int r){return get(r+1)-get(l);}
};
