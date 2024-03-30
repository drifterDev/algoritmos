// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())

// O(m*n) 
int editDist(string& x, string& y){
	int m=sz(x), n=sz(y);
	int dp[m+1][n+1];
	for(int i=0;i<=m;++i){
		for(int j=0;j<=n;++j){
			if(i==0)dp[i][j]=j;
			else if(j==0)dp[i][j]=i;
			else if(x[i-1]==y[j-1])dp[i][j]=dp[i-1][j-1];
			else dp[i][j]=1+min({dp[i][j-1],  // Insert
													dp[i-1][j],  // Remove
													dp[i-1][j-1]}); // Replace
		}
	}
	return dp[m][n];
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	string s1="love", s2="movie";
	cout<<editDist(s1, s2)<<"\n";
	return 0;
}
