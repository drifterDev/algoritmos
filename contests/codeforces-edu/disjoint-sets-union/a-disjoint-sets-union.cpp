// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

struct dsu{
	vector<int> p,size;
	int sets,maxSz;

	dsu(int n){
		sets=n;
		maxSz=1;
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
		maxSz=max(maxSz,size[b]);
		sets--;
	}
};

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    dsu d(n);
    string s;
    int a,b;
    while(q--){
        cin>>s>>a>>b;
        if(s=="union"){
            d.unionSets(a-1,b-1);
        }else{
            cout<<(d.get(a-1)==d.get(b-1)?"YES":"NO")<<"\n";
        }
    }
    return 0;
}
