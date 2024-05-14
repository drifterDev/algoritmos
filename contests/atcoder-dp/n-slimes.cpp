// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> pre;

ll cost(int i, int j){
	return pre[j+1]-pre[i];
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n;cin>>n;
	pre.assign(n+1,1);
	for(int i=1;i<=n;++i){
		cin>>pre[i];
		pre[i]+=pre[i-1];
	}

	vector<vector<ll>> dp(n+1, vector<ll>(n+1,LONG_LONG_MAX));
	
	for(int i=0;i<n;++i)dp[i][i]=0;
	for(int j=1;j<=n;++j){
		for(int i=0;i<n-j;++i){
			dp[i][i+j]=dp[i+1][i+j]+cost(i,i)+cost(i+1,i+j);
			for(int k=i+1;k<=i+j;++k){
				ll tmp=cost(i,k-1)+cost(k, i+j)+dp[i][k-1]+dp[k][i+j];
				dp[i][i+j]=min(dp[i][i+j], tmp);
			}
		}
	}

	cout<<dp[0][n-1]<<"\n";
	return 0;
}
