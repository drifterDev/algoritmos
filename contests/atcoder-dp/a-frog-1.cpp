// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n;cin>>n;
	vi h(n);
	for(int i=0;i<n;++i)cin>>h[i];
	vi dp(n,INT_MAX);
	dp[0]=0;
	for(int i=0;i<n-1;++i){
		dp[i+1]=min(dp[i+1], dp[i]+abs(h[i]-h[i+1]));
		if(i==n-2)continue;
		dp[i+2]=min(dp[i+2], dp[i]+abs(h[i]-h[i+2]));
	}
	cout<<dp[n-1]<<"\n";
	return 0;	
}