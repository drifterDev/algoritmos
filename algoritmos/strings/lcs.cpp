// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define len(str) ((int) str.length())
const int nMax = 1005;
int dp[nMax][nMax];
// Longest Common Subsequence
// O(n*m)
int lcs(const string &s, const string &t){
  int n=len(s),m=len(t);
  for(int i=0;i<m+1;i++)dp[0][i] = 0;
  for(int i=0;i<n+1;i++)dp[i][0] = 0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      if(s[i-1]==t[j-1])dp[i][j]=max(dp[i][j], dp[i-1][j-1] + 1);
    }
  }
  return dp[n][m];
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
string s,t;
cin>>s>>t;
cout<<lcs(s,t)<<"\n";
return 0;
}