// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n;cin>>n;
	vl nums(n);
	for(int i=0;i<n;++i)cin>>nums[i];
	// estados: [l,r]
	vector<vl> dp(n,vl(n,0));
	for(int i=0;i<n;++i)dp[i][i]=nums[i];
	for(int i=1;i<n;++i){
		for(int j=0;j<n-i;++j){
			ll op1=nums[j+i]-dp[j][j+i-1];
			ll op2=nums[j]-dp[j+1][j+i];
			dp[j][j+i]=max(op1, op2);
		}
	}
	cout<<dp[0][n-1]<<"\n";
	return 0;
}