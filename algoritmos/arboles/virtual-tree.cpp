#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
const int maxlog = 20+5; 
const int maxn = 2e5+5;
vector<int> adjVT[maxn];
vector<int> adj[maxn];
int st[maxn], ft[maxn];
bool important[maxn];
int up[maxn][maxlog];
int dep[maxn];
int n,q,pos=0; 

void dfs(int v, int p=-1){
    up[v][0]=p;
    st[v]=++pos;
	for(int u:adj[v]){
		if(u==p)continue;
        dep[u]=dep[v]+1;
        dfs(u, v);
	}
    ft[v]=pos;
}

void buildLCA();
int lca(int a, int b);
bool upper(int v, int u){return st[v]<=st[u] && ft[v]>=ft[u];}
bool cmp(int v, int u){return st[v]<st[u];}

// return root, O(klogk)
int virtualTree(vector<int> nodes){
    sort(all(nodes), cmp);
    int m=sz(nodes);
    for(int i=0;i<m-1;++i){
        int v=lca(nodes[i], nodes[i+1]);
        nodes.push_back(v);
    }

    sort(all(nodes), cmp);
    nodes.erase(unique(all(nodes)), nodes.end());
    for(int u:nodes)adjVT[u].clear();

    vector<int> s;
    s.push_back(nodes[0]);
    m=sz(nodes);
    for(int i=1;i<m;++i){
        int v=nodes[i];
        while(sz(s)>=2 && !upper(s.back(), v)){
            adjVT[s[sz(s)-2]].push_back(s.back()); // add edge
            s.pop_back();
        }
        s.push_back(v);
    }
    while(sz(s)>=2){
        adjVT[s[sz(s)-2]].push_back(s.back()); // add edge
        s.pop_back();
    }
    return s[0];
}

void reset(){
    for(int i=0;i<n;++i){
        for(int l=0;l<maxlog;++l)up[i][l]=-1;
        adj[i].clear();
    }
    pos=0;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    memset(important, 0, sizeof(important)); 
	memset(up, -1, sizeof(up)); 
    int t;
    cin>>t;
    while(t--){
        cin>>n>>q;
        // input tree
        dep[0]=0;
        dfs(0);
        buildLCA();
        while(q--){
            int k;cin>>k;
            vector<int> nodes(k);
            for(int& x:nodes){
                cin>>x;x--;
                important[x]=true;
            }
            int root=virtualTree(nodes);
            // solve(root);
            // output answer
            for(int x:nodes)important[x]=false;
        }
        reset();
    }
    return 0;
}
