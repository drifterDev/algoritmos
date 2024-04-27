// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
int act;

struct dsu{
	vector<vector<int>> l;
	vector<int> p,ans;

	dsu(int n){
		p.assign(n,0);
		ans.assign(n,-1);
		l.assign(n,vector<int>());
		iota(p.begin(), p.end(), 0);
		for(int i=0;i<n;++i)l[i].push_back(i);
	}

    bool estaUno(int a, int b){
        if(a==0 || b==0)return true;
        return a==p[0] || b==p[0];
    }

	void unionSets(int a, int b){
		a=p[a];
		b=p[b];
		if(a==b)return;
		if(l[a].size()>l[b].size())swap(a, b);
        int time=-1;
        if(estaUno(a,b)){
            time=act;
            if(a==0 || a==p[0])swap(b,a);
        }
        for(auto x:l[a]){
            ans[x]=time;
            l[b].push_back(x);
            p[x]=b;
        }
        l[a].clear();
	}

    void unionSets2(int a, int b){
		a=p[a];
		b=p[b];
		if(a==b)return;
		if(l[a].size()>l[b].size())swap(a, b);
        for(auto x:l[a]){
            l[b].push_back(x);
            p[x]=b;
        }
        l[a].clear();
	}
};

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    act=m-1;
    map<int, pair<int,int>> mp;
    set<tuple<int,int,int>> s;
    int a,b;
    for(int i=1;i<=n;++i){
        cin>>a>>b;
        mp[i]={a,b};
        if(a!=-1)s.insert({i,a,1});
        if(b!=-1)s.insert({i,b,2});
    }
    vector<pair<int,int>> queries(m);
    int c,m2=m;
    while(m2--){
        cin>>a>>b;
        queries[m2]={a,b};
        c=(b==1?mp[a].first:mp[a].second);
        auto it=s.find({a,c,b});
        if(it!=s.end())s.erase(it);
    }
    dsu uf(n);
    for(auto x:s){
        a=get<0>(x);
        b=get<1>(x);
        uf.unionSets2(a-1,b-1);
    }

    for(auto x:queries){
        a=x.first;
        if(x.second==1)b=mp[a].first;
        else b=mp[a].second;
        uf.unionSets(a-1,b-1);
        act--;
    }

    for(auto x:uf.ans){
        cout<<x<<"\n";
    }
    return 0;
}