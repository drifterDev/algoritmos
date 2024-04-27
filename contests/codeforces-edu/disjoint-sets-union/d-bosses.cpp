// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

struct dsu{
	vector<int> p,ans;

	dsu(int n){
		p.assign(n,0);
		ans.assign(n,0);
		iota(p.begin(),p.end(),0);
	}

	int get(int a){
		if(a!=p[a]){
			int v=p[a];
            p[a]=get(v);
			ans[a]+=ans[v];
        }
		return p[a];
	}

	void unionSets(int a, int b){
		a=get(a);
		b=get(b);
		if(a==b)return;
		p[a]=b;
		ans[a]=ans[b]+1;
	}
};


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    dsu uf(n);
    int a,b,c;
    while(m--){
        cin>>c>>a;
        if(c==1){
            cin>>b;
            uf.unionSets(a-1,b-1);
        }else{
			uf.get(a-1);
            cout<<uf.ans[a-1]<<"\n";
        }
    }
    return 0;
}
