// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

struct dsu{
	vector<int> p,size,mini,maxi;
	int sets,maxSz;

	dsu(int n){
		sets=n;
		maxSz=1;
		p.assign(n,0);
		maxi.assign(n,0);
		mini.assign(n,0);
		size.assign(n,1);
		iota(p.begin(),p.end(),0);
		iota(mini.begin(),mini.end(),0);
		iota(maxi.begin(),maxi.end(),0);
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
        maxi[b]=max(maxi[b], maxi[a]);
        mini[b]=min(mini[b], mini[a]);
		sets--;
	}
};

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,m,q,q2,a,b;
    cin>>n>>m>>q;
    q2=q;
    while(m--){
        cin>>a>>b;
    }
    vector<string> ans;
    vector<pair<pair<int, int>,int>> queries(q);
    string s;
    while(q2--){
        cin>>s>>a>>b;
        queries[q2]={{a,b},(s=="ask"?1:0)};
    }
    dsu uf(n);
    for(auto querie:queries){
        a=querie.first.first-1;
        b=querie.first.second-1;
        if(querie.second==1){
            s=(uf.get(a)==uf.get(b)?"YES":"NO");
            ans.push_back(s);
        }else{
            uf.unionSets(a, b);
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto x:ans)cout<<x<<"\n";
    return 0;
}
