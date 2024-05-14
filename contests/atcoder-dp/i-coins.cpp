// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cout<<setprecision(10)<<fixed;
	int n;cin>>n;
	vector<double> p(n);
	for(int i=0;i<n;++i)cin>>p[i];
	// estados: [n, probabilidad de x caras]
	vector<vector<double>> dp(n+1,vector<double>(n+1,0));
	dp[0][0]=1;
	for(int i=1;i<=n;++i)dp[0][i]=dp[0][i-1]*(1-p[i-1]);
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			dp[i][j]=dp[i-1][j-1]*p[j-1]+dp[i][j-1]*(1-p[j-1]);
		}
	}
	double ans=0;
	for(int i=n/2+1;i<=n;++i)ans+=dp[i][n];
	cout<<ans<<"\n";
	return 0;
}