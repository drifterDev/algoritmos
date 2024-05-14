// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"
typedef vector<int> vi;
const int MOD = 1e9+7;

int suma(int x_1,int y_1){
  	return ((x_1%MOD)+(y_1%MOD))%MOD;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,m;cin>>n>>m;
	vector<vi> dp(n+1, vi(m+1,0));
	char c;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>c;
			if(c=='#')dp[i+1][j+1]=-1;
		}
	}
	dp[1][1]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(dp[i][j]==-1)continue;
			if(dp[i-1][j]!=-1)dp[i][j]=suma(dp[i][j], dp[i-1][j]);
			if(dp[i][j-1]!=-1)dp[i][j]=suma(dp[i][j], dp[i][j-1]);
		}
	}
	cout<<dp[n][m]<<"\n";
	return 0;
}