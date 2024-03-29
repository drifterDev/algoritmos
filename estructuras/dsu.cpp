// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;

struct dsu{
	vl parents,sizes;
	ll numSets;
	ll maxSz;

	dsu(ll n){
		parents.assign(n,0);
		sizes.assign(n,1);
		numSets=n;
		maxSz=1;
		for(int i=0;i<n;++i)parents[i]=i;
	}

	ll findSet(ll v){
		if(v==parents[v])return v;
		return parents[v]=findSet(parents[v]);
	}

	bool isSameSet(ll i,ll j){
		return findSet(i)==findSet(j);
	}

	void unionSets(ll a, ll b){
		a=findSet(a);
		b=findSet(b);
		if(a!=b){
			if(sizes[a]<sizes[b])swap(a, b);
			parents[b]=a;
			sizes[a]+=sizes[b];
			maxSz=max(maxSz,sizes[a]);
			numSets--;
		}
	}
};
