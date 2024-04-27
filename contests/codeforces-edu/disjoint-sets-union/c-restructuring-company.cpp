// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

struct dsu{
	vector<int> p,size;
    set<int> s1,s2;
    set<pair<int,int>> s3;

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

struct dsu2{
	vector<int> p,size;
    set<int> s1,s2;
    set<pair<int,int>> s3;

	dsu2(int n){
		p.assign(n,0);
		size.assign(n,1);
		iota(p.begin(),p.end(),0);
	}

	int get(int a){
		if(a!=p[a])p[a]=get(p[a]);
		return p[a];
	}

	void unionSets(int a, int b, dsu& uf){
		if(get(a)==get(b))return;
        a=get(a);
        while(a<b){
            uf.unionSets(a,a+1);
            p[a]=get(a+1);
            a=p[a];
        }
	}
};

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    dsu uf(n);
    dsu2 uf2(n);
    int a,b,c;
    while(q--){
        cin>>a>>b>>c;
        b--;c--;
        if(a==1){
            uf.unionSets(uf2.get(b),uf2.get(c));
        }else if(a==2){
            uf2.unionSets(b,c,uf);
        }else{
            cout<<(uf.get(b)==uf.get(c)?"YES":"NO")<<"\n";
        }
    }
    return 0;
}
