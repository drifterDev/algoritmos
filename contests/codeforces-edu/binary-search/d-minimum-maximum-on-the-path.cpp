// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> adj;
vector<int> dist,p;
int n,m,d;

bool bfs(int s){
    queue<int> q;
    q.push(1);
    dist.assign(n+1, -1);
    p.assign(n+1, -1);
    dist[1]=0;
    while(!q.empty()){
        int v=q.front();q.pop();
        if(dist[v]==d)continue;
        for(auto act:adj[v]){
            int u=act.first,w=act.second;
            if(dist[u]!=-1)continue;
            if(w>s)continue;
            dist[u]=dist[v]+1;
            p[u]=v;
            q.push(u);
        }
    }
    return dist[n]!=-1;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n>>m>>d;
    adj.assign(n+1, vector<pair<int,int>>());
    for(int a,b,c,i=0;i<m;++i){
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    int l=0,r=1e9+1;
    while(l<=r){
        int m=l+(r-l)/2;
        if(bfs(m)){
            r=m-1;
        }else{
            l=m+1;
        }
    }
    if(!bfs(r+1)){
        cout<<"-1\n";
        return 0;
    }   
    vector<int> path;
    for(int u=n;u!=-1;u=p[u]){
        path.push_back(u);
    }
    reverse(path.begin(), path.end());
    cout<<path.size()-1<<"\n";
    for(auto x:path){
        cout<<x<<" ";
    }cout<<"\n";
    return 0;
}
