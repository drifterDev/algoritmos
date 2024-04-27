// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

struct dsu{
    stack<pair<int,pair<int,int>>> s;
	vector<int> p,rank;
    int sets;

	dsu(int n){
        sets=n;
		p.assign(n,0);
		rank.assign(n,1);
		iota(p.begin(), p.end(), 0);
	}

	int get(int a){
        if(a==p[a])return a;
		return get(p[a]);
	}

	void unionSets(int a, int b){
		a=get(a);
		b=get(b);
		if(a==b)return;
        if(rank[a]>rank[b])swap(a,b);
        s.push({a, {rank[a], rank[b]}});
        rank[a]++;
        rank[b]=max(rank[a], rank[b]);
        p[a]=b;
        sets--;
	}

    void persist(){
        s.push({-1,{-1,-1}});
    }

    void rollback(){
        int a,ra,rb;
        while(!s.empty()){
            auto act=s.top();
            s.pop();
            a=act.first;
            ra=act.second.first;
            rb=act.second.second;
            if(a==-1)break;
            rank[p[a]]=rb;
            rank[a]=ra;
            p[a]=a;
            sets++;
        }
    }
};

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    string s;
    int a,b;
    dsu uf(n);
    while(m--){
        cin>>s;
        if(s=="persist"){
            uf.persist();
        }else if(s=="union"){
            cin>>a>>b;
            uf.unionSets(a-1,b-1);
            cout<<uf.sets<<"\n";
        }else{
            uf.rollback();
            cout<<uf.sets<<"\n";
        }
    }
    return 0;
}
