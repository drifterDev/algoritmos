// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

struct dsu{
	vector<vector<int>> l;
	vector<int> p,val,before;

	dsu(int n){
		p.assign(n,0);
		val.assign(n,0);
		before.assign(n,0);
		l.assign(n,vector<int>());
		iota(p.begin(), p.end(), 0);
		for(int i=0;i<n;++i)l[i].push_back(i);
	}

	int get(int a){
		if(a!=p[a])return val[a]+val[p[a]]-before[a];
		return val[a];
	}

	void add(int a,int x){
		if(a!=p[a])val[p[a]]+=x;
		else val[a]+=x;
	}

	void unionSets(int a, int b){
		a=p[a];
		b=p[b];
		if(a==b)return;
		if(l[a].size()>l[b].size())swap(a, b);
		for(auto x:l[a]){
			l[b].push_back(x);
			p[x]=b;
			if(x!=a)val[x]+=val[a]-before[x];
			before[x]=val[b];
		}
		l[a].clear();
	}
};

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,q;
	cin>>n>>q;
	dsu uf(n);
	string s;
	int a,b;
	while(q--){
		cin>>s>>a;
		if(s=="add"){
			cin>>b;
			uf.add(a-1, b);
		}else if(s=="join"){
			cin>>b;
			uf.unionSets(a-1, b-1);
		}else{
			cout<<uf.get(a-1)<<"\n";
		}
	}
	return 0;
}
