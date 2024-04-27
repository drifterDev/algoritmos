// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

struct dsu{
	vector<int> p;
    int n;

	dsu(int n2){
        n=n2;
		p.assign(n+1,0);
		iota(p.begin(),p.end(),0);
	}

	int get(int a){
		if(a!=p[a])p[a]=get(p[a]);
		return p[a];
	}

	void erase(int a){
        p[a]=p[(a+1>n?1:a+1)];
    }
};

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n;cin>>n;
    dsu uf(n);
    for(int i=0,a;i<n;++i){
        cin>>a;
        cout<<uf.get(a)<<" ";
        uf.erase(uf.get(a));
    }
    return 0;
}
