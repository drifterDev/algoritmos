// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
vector<tuple<int,int,int>> edges;
int n,m;

struct dsu{
	vector<int> p,size;

	dsu(int n){
		p.assign(n,0);
		size.assign(n,1);
		iota(p.begin(),p.end(),0);
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
	}
};

pair<bool, int> check(int x2){
	dsu uf(n);
	int a,b,c,ans=0,maxi=x2;
	for(auto x:edges){
		a=get<1>(x);
		b=get<2>(x);
		c=get<0>(x);
		if(c<x2)continue;
		if(uf.get(a)==uf.get(b))continue;
		uf.unionSets(a,b);
		ans++;
		maxi=max(maxi, c);
	}
	return {ans==n-1, maxi};
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	map<int, bool> mp;
	vector<int> vals;
	for(int a,b,c,i=0;i<m;++i){
		cin>>a>>b>>c;
		edges.push_back({c,a-1,b-1});
		if(!mp[c]){
			mp[c]=true;
			vals.push_back(c);
		}
	}
	sort(edges.begin(), edges.end());
	sort(vals.begin(), vals.end());
	bool flag=false;
	int ans=INT_MAX;
	m=vals.size();
	for(int i=0;i<m;++i){
		pair<bool, int> tmp=check(vals[i]);
		if(!tmp.first)continue;
		flag=true;
		ans=min(ans, tmp.second-vals[i]);
	}
	if(!flag){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n"<<ans<<"\n";
    return 0;
}
