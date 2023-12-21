// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
const int n = 1005;
int dp[n][n];

// Longest Common Subsequence
// O(n*m)
int lcs(const string &s, const string &t){
  int n=sz(s),m=sz(t);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      if(s[i-1]==t[j-1])dp[i][j]=max(dp[i][j], dp[i-1][j-1] + 1);
    }
  }
  return dp[n][m];
}

string lcs_str(const string &s, const string &t){
  int n=sz(s),m=sz(t);
  for(int i=1;i<=n;++i){
    for(int j=1;j<=m;++j){
      if(s[i-1]==t[j-1])dp[i][j]=dp[i-1][j-1]+1;
      else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
  }
  int i=n,j=m;
  string res="";
  while(i>0 && j>0) {
      if(s[i - 1]==t[j-1]){
        res=s[i-1]+res;i--;j--;
      }else if(dp[i-1][j]>dp[i][j-1])i--;
      else j--;
  }
  return res;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s,t;
  cin>>s>>t;
  cout<<lcs(s,t)<<"\n";
  cout<<lcs_str(s,t)<<"\n";
  return 0;
}