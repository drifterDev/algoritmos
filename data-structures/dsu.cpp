#include <bits/stdc++.h>
using namespace std;

struct DSU{
	vector<int> p,size;
	DSU(int n){
		p.assign(n,0);
		size.assign(n,1);
		for(int i=0;i<n;++i)p[i]=i;
	}
	int get(int a){return (a==p[a]?a:p[a]=get(p[a]));} // path compression
	int get(int a){return (a==p[a]?a:get(p[a]));}
	void unite(int a, int b){
		a=get(a);b=get(b);
		if(a==b)return;
		if(size[a]>size[b])swap(a, b);
		p[a]=b;size[b]+=size[a];
	}
};