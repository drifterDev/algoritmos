typedef pair<ll, int> par;
typedef vector<ll> vl;
const int maxn = 1e5;
const ll inf = 1e18;
vector<par> adj[maxn];

// O((n+m)log(m))
vl dijkstra(int s, int n){
	priority_queue<par, vector<par>, greater<par>> pq;
	vl dist(n, inf); 
	pq.push({0, s});
	dist[s]=0;
	while(!pq.empty()){
		auto [d,u]=pq.top();pq.pop();
		if(d>dist[u])continue;
		for(auto [w,v]:adj[u]){
			if(dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;
				pq.push({dist[v],v});
			}
		}
	}
	return dist;
}
