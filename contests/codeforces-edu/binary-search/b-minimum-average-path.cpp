// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, long double>>> adj;
vector<int> p;
int n,m;

bool f(long double x){
    p.assign(n+1, -1);
	vector<long double> dist(n+1, LONG_LONG_MAX); 
	dist[1]=0;
    for(auto u:adj[1]){
        dist[u.first]=u.second-x;
        p[u.first]=1;
    }
	for(int i=2;i<=n;++i){
        for(auto u:adj[i]){
            long double act=dist[i]+(u.second-x);
            if(dist[u.first]>act){
                dist[u.first]=act;
                p[u.first]=i;
            }
        }
    }
    return dist[n]>0;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n>>m;
    adj.assign(n+1, vector<pair<int,long double>>());
    long double c;
    for(int a,b,i=0;i<m;++i){
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    long double l=0,r=1e2;
    while(r-l>=1e-7){
        long double m=l+(r-l)/2;
        if(f(m)){
            l=m;
        }else{
            r=m;
        }
        // cout<<m<<"\n";
    }
    f(r);
    vector<int> path;
    for(int i=n;i!=-1;i=p[i]){
        path.push_back(i);
    }
    reverse(path.begin(), path.end());
    cout<<path.size()-1<<"\n";
    for(auto y:path)cout<<y<<" ";
    cout<<"\n";
    return 0;
}
