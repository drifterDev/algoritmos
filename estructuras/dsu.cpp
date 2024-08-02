#include <bits/stdc++.h>
using namespace std;

// path compression
struct dsu{
	vector<int> p,size;
	int sets,maxSz;

	dsu(int n){
		sets=n;
		maxSz=1;
		p.assign(n,0);
		size.assign(n,1);
		for(int i=0;i<n;++i)p[i]=i;
	}

	int get(int a){
		if(a!=p[a])p[a]=get(p[a]);
		return p[a];
	}

	void unionSets(int a, int b){
		a=get(a);
		b=get(b);
		if(a==b)return;
		if(size[a]>size[b])swap(a, b);
		p[a]=b;
		size[b]+=size[a];
		maxSz=max(maxSz,size[b]);
		sets--;
	}
};

// rank heuristic
struct dsu{
	vector<int> p,rank;

	dsu(int n){
		p.assign(n,0);
		rank.assign(n,1);
		for(int i=0;i<n;++i)p[i]=i;
	}

	int get(int a){
        if(a==p[a])return a;
		return get(p[a]);
	}

	void unionSets(int a, int b){
		a=get(a);
		b=get(b);
		if(a==b)return;
        if(rank[a]>rank[b])swap(a,b);
        rank[b]+=rank[a];
        p[a]=b;
	}
};

// Bipartite graph
struct dsu{
	vector<int> p,size,len;

	dsu(int n){
		p.assign(n,0);
		len.assign(n,0);
		size.assign(n,1);
		for(int i=0;i<n;++i)p[i]=i;
	}

	pair<int,int> get(int a){
		if(a==p[a]){
			return {a, 0};
		}
		pair<int,int> valA=get(p[a]);
		p[a]=valA.first;
		len[a]=(len[a]+valA.second)%2;
		return {p[a], len[a]};
	}

	void unionSets(int a, int b){
		pair<int,int> valA=get(a);
		pair<int,int> valB=get(b);
		if(valA.first==valB.first)return;
		if(size[valA.first]>size[valB.first]){
			swap(valA,valB);
		}
		p[valA.first]=valB.first;
		len[valA.first]=(valA.second+valB.second+1)%2;
		size[valB.first]+=size[valA.first];
	}
};