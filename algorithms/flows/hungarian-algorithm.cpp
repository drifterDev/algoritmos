#include <bits/stdc++.h>
using namespace std;

// task assignment O(n^3)
template <class type>
vector<int> hungarian(const vector<vector<type>>& cost){
	const type inf=numeric_limits<type>::max();
	int js=cost.size(); // jobs
	int ws=cost[0].size(); // workers
	vector<int> job(ws+1,-1); // -1 no assigned
	vector<type> h(ws); 

	for(int ji=0;ji<js;++ji){
		int wi=ws;job[wi]=ji;
		vector<type> dist(ws+1,inf);
		dist[ws] = 0;
		vector<bool> vis(ws+1); 
		vector<int> prv(ws+1,-1); 
		while(job[wi]!=-1){
			type min_dist=inf;
			vis[wi]=true;
			int w_next=-1; 
			for(int w=0;w<ws;++w){
				if(!vis[w]){
					type edge=cost[job[wi]][w]-h[w];
					if(wi!=ws)edge-=cost[job[wi]][wi]-h[wi];
					if(dist[w]>dist[wi]+edge){
						dist[w]=dist[wi]+edge;
						prv[w]=wi;
					}
					if(min_dist>dist[w]){
						min_dist=dist[w];
						w_next=w;
					}
				}
			}
			wi=w_next;
		}
		for(int w=0;w<ws;++w){ 
			dist[w]=min(dist[w],dist[wi]);
			h[w]+=dist[w];
		}
		while(wi!=ws){
			job[wi]=job[prv[wi]];
			wi=prv[wi];
		}
	}
	return job;
}
