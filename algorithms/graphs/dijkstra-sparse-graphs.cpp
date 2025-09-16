typedef pair<ll, int> par;
typedef vector<ll> vl;
const int maxn = 1e5;
const ll inf = 1e18;
vector<par> adj[maxn];

// O(mlog(n)), m => n^2
vl dijkstra(int s, int n){
	set<par> pq;
	pq.insert({0, s});
	vl dist(n, inf); 
	dist[s]=0;
	while(!pq.empty()){
		auto [d,u]=*pq.begin();
        pq.erase(pq.begin());
		for(auto [w,v]:adj[u]){
			if(dist[u]+w<dist[v]){
				pq.erase({dist[v],v});
				dist[v]=dist[u]+w;
				pq.insert({dist[v],v});
			}
		}
	}
	return dist;
}
