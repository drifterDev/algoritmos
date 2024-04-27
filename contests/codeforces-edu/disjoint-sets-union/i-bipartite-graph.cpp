// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

struct dsu{
	vector<int> p,size,len;

	dsu(int n){
		p.assign(n,0);
		len.assign(n,0);
		size.assign(n,1);
		iota(p.begin(),p.end(),0);
	}

	pair<int,int> get(int a){
		if(a==p[a]){
			return {a, 0};
		}
		pair<int,int> valA=get(p[a]);
		p[a]=valA.first;
		len[a]=(len[a]+valA.second)%2;
		return {p[a], len[a]};
	}

	void unionSets(int a, int b){
		pair<int,int> valA=get(a);
		pair<int,int> valB=get(b);
		if(valA.first==valB.first)return;
		if(size[valA.first]>size[valB.first]){
			swap(valA,valB);
		}
		p[valA.first]=valB.first;
		len[valA.first]=(valA.second+valB.second+1)%2;
		size[valB.first]+=size[valA.first];
	}
};

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    dsu uf(n);
    int a,b,c,shift=0;
    while(q--){
        cin>>a>>b>>c;
        b--;c--;
        b=(b+shift)%n;
        c=(c+shift)%n;
        if(a==0){
            uf.unionSets(b,c);
        }else{
            pair<int,int> valb=uf.get(b);
            pair<int,int> valc=uf.get(c);
            if(valb.first==valc.first){
                if(valb.second==valc.second){
                    cout<<"YES\n";
                    shift=(shift+1)%n;
                    continue;
                }
            }
            cout<<"NO\n";
        }
    }
    return 0;
}
