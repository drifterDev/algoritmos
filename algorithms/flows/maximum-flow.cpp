// O(m*n^2) - redes unitarias O(m*sqrt(n))
template <class type> 
struct network{
	const type inf=numeric_limits<type>::max();
	struct edge{int v;type cap;int inv;type flow;};
	int n,s,t;
	vector<int> lvl;
	vector<vector<edge>> g;
	network(int n):n(n),lvl(n),g(n){}
	void add_edge(int u, int v, int c){
		// edges.push_back({u,v});
		g[u].push_back({v, c, sz(g[v]), 0});
		g[v].push_back({u, 0, sz(g[u])-1, c});
	}

	bool bfs(){
		fill(lvl.begin(),lvl.end(),-1);
		queue<int> q;
		lvl[s]=0;
		for(q.push(s);q.size();q.pop()){
			int u=q.front();
			for(auto &e:g[u]) {
				if(e.cap>0 && lvl[e.v]==-1){
					lvl[e.v]=lvl[u]+1;
					q.push(e.v);
				}
			}
		}
		return lvl[t]!=-1;
	}

	type dfs(int u, type nf){
		if(u==t)return nf;
		type res=0;
		for(auto &e:g[u]){
			if(e.cap>0 && lvl[e.v]==lvl[u]+1){
				type tf=dfs(e.v, min(nf, e.cap));
				res+=tf;nf-=tf;e.cap-=tf;
				g[e.v][e.inv].cap+=tf;
				g[e.v][e.inv].flow-=tf;
				e.flow+=tf;
				if(nf==0)return res;
			}
		}
		if(!res)lvl[u]=-1;
		return res;
	}

	type max_flow(int so, int si, type res=0){
		s=so;t=si;
		while(bfs())res+=dfs(s, inf);
		return res;
	}

	vector<pair<int,int>> edges;
	void min_cut(int so, int si){
		cout<<max_flow(so, si)<<"\n";bfs();
		for(auto& [a,b]:edges){
			if(lvl[a]!=-1 && lvl[b]==-1){
				cout<<a+1<<" "<<b+1<<"\n";
			}
		}
	}
};

