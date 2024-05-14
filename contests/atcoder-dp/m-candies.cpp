// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int MOD = 1e9+7;

int mod(int a, int m){
  	return ((a%m)+m)%m;
}

int resta(int x, int y){
  	return mod((mod(x,MOD)-mod(y,MOD)),MOD);
}

int suma(int x, int y){
  	return mod((mod(x,MOD)+mod(y,MOD)),MOD);
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,w;
	cin>>n>>w;
	vi nums(n);
	// estados: [#candies, n]
	vector<vi> dp(w+1, vi(n+1,0));

	for(int i=0;i<n;++i)cin>>nums[i];
	for(int i=0;i<=n;++i)dp[0][i]=1;
	for(int i=0;i<=w;++i)dp[i][0]=1;

	for(int i=1;i<=w;++i){
		for(int j=1;j<=n;++j){
			dp[i][j]=dp[i][j-1];
			if(i-nums[j-1]>0){
				dp[i][j]=resta(dp[i][j], dp[i-nums[j-1]-1][j-1]);
			}
			dp[i][j]=suma(dp[i][j], dp[i-1][j]);
		}
	}

	int ans=dp[w][n];
	if(w>0)ans=resta(ans, dp[w-1][n]);
	cout<<ans<<"\n";
	return 0;
}