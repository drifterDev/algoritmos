// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<tuple<ll, int, int>> edges;
    ll c;int a,b;
    for(int i=0;i<m;++i){
        cin>>a>>b>>c;
        edges.push_back({c,a-1,b-1});
    }
    sort(edges.begin(),edges.end());
    dsu uf(n);
    ll ans=0;
    for(auto x:edges){
        a=get<1>(x);
        b=get<2>(x);
        c=get<0>(x);
        if(uf.get(a)==uf.get(b))continue;
        uf.unionSets(a,b);
        ans=max(ans, c);
    }
    cout<<ans<<"\n";
    return 0;
}
