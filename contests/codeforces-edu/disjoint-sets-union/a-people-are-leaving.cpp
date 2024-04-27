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
		if(a!=p[a] && p[a]!=-1)p[a]=get(p[a]);
		return p[a];
	}

	void erase(int a){
        if(a==n)p[a]=-1;
        else p[a]=p[a+1];
    }
};

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    char c;int a;
    dsu uf(n);
    while(m--){
        cin>>c>>a;
        if(c=='?'){
            cout<<uf.get(a)<<"\n";
        }else{
            uf.erase(a);
        }
    }
    return 0;
}
