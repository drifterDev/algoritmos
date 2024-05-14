// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,w;cin>>n>>w;
	vl ws(n);vi vs(n);
	for(int i=0;i<n;++i){
		cin>>ws[i]>>vs[i];
	}
	int maxn=1e5;
	vector<vl> dp(n+1, vl(maxn+1, LONG_LONG_MAX));
	for(int i=0;i<=n;++i)dp[i][0]=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=maxn;++j){
			dp[i][j]=dp[i-1][j];
			if(j-vs[i-1]>=0){
				if(dp[i-1][j-vs[i-1]]==LONG_LONG_MAX)continue;
				ll tmp=dp[i-1][j-vs[i-1]]+ws[i-1];
				dp[i][j]=min(tmp, dp[i][j]);
			}
		}
	}

	int ans=0;
	for(int i=0;i<=maxn;++i){
		if(dp[n][i]>w)continue;
		ans=i;
	}
	cout<<ans<<"\n";
	return 0;
}