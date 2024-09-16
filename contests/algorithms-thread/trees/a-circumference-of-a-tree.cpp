#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
const int maxn = 3e5+1;
int dist[maxn];
int n;

void dfs(int v, int p=-1){
    for(int u:adj[v]){
        if(u!=p){
            dist[u]=dist[v]+1;
            dfs(u,v);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    memset(dist, 0, sizeof(dist));
    cin>>n;
    adj.assign(n, vector<int>());
    for(int a,b,i=1;i<n;++i){
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0);
    int ans=0,id=0;
    for(int i=0;i<n;++i){
        if(ans<dist[i]){
            ans=dist[i];
            id=i;
        }
    }
    memset(dist, 0, sizeof(dist));
    dfs(id);
    ans=0;
    for(int i=0;i<n;++i)ans=max(ans, dist[i]);
    cout<<ans*3<<"\n";
    return 0;
}
