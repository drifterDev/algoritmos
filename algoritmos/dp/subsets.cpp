// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int k,n;
	cin>>k>>n;
	vector<vector<int>> dp(1<<k, vector<int>(n,1e9));
	vector<vector<int>> price(k,vector<int>(n,0));
	
	dp[0][0]=0;
	for(int x=0;x<k;++x){
		for(int j=0;j<n;++j){
			cin>>price[x][j];
		}
		dp[1<<x][0]=price[x][0];
	}

	for(int d=1;d<n;++d){
		for(int s=0;s<(1<<k);++s){
			dp[s][d]=dp[s][d-1];
			for(int x=0;x<k;++x){
				if(s&(1<<x)){
					dp[s][d]=min(dp[s][d], dp[s^(1<<x)][d-1]+price[x][d]);
				}
			}
		}
	}

	cout<<dp[(1<<k)-1][n-1]<<"\n";
	return 0;
}
