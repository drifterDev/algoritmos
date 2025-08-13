const int maxn = 300;
const int inf = 1e9;
int adj[maxn][maxn]; 
// inf si no existe y adj[i][i]=0

// O(n^3)
void floyd(int n){
	for(int k=0;k<n;++k){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(adj[i][k]==inf || adj[k][j]==inf)continue;
				adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]); 
			}
		}
	}
}
