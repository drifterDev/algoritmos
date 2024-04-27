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
    ll s;
    int n,m;
    cin>>n>>m>>s;
    vector<tuple<ll, int, int,int>> edges;
    ll c;int a,b;
    for(int i=0;i<m;++i){
        cin>>a>>b>>c;
        edges.push_back({c,a-1,b-1,i+1});
    }
    sort(edges.rbegin(),edges.rend());
    dsu uf(n);
    vector<pair<ll,int>> edges2;
    for(auto x:edges){
        a=get<1>(x);
        b=get<2>(x);
        c=get<0>(x);
        if(uf.get(a)==uf.get(b)){
            edges2.push_back({c, get<3>(x)});
            continue;            
        }
        uf.unionSets(a,b);
    }
    sort(edges2.begin(), edges2.end());
    vector<int> ans;
    ll res=s;
    for(auto x:edges2){
        if(res-x.first<0)break;
        res-=x.first;
        ans.push_back(x.second);
    }
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<"\n";
    for(auto x:ans)cout<<x<<" ";
    return 0;
}
