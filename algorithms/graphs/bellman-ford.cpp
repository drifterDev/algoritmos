typedef pair<ll, int> par;
const int maxn = 1e5;
const ll inf = 1e18;
vector<par> adj[maxn];

// O(n*m)
bool bellman(int s, int n){
	vector<ll> dist(n,inf);
	dist[s]=0;
	for(int i=0;i<=n;++i){
		bool change=0;
		for(int u=0;u<n;++u){
			if(dist[u]==inf)continue;
			for(auto [w,v]:adj[u]){
				if(dist[u]+w>=dist[v])continue;
				if(i==n)return true;
				dist[v]=dist[u]+w;
				change=1;
			}
		}
		if(!change)break;
	}
	return false;
}

// para ciclos
// for(int i=0;i<n;++i)ini=dad[ini];
// vector<int> cycle;
// cycle.push_back(ini+1);
// for(int u=dad[ini];u!=ini;u=dad[u])cycle.push_back(u+1);
// cycle.push_back(ini+1);
// reverse(all(cycle));
// print(cycle);
