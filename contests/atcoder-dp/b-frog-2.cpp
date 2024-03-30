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
  cout<<setprecision(20)<<fixed;
  // freopen("file.in", "r", stdin);
  // freopen("file.out", "w", stdout);
  int n,k;cin>>n>>k;
  vi h(n);
  for(int i=0;i<n;++i)cin>>h[i];
  vi dp(n,INT_MAX);
  dp[0]=0;
  for(int i=0;i<n-1;++i){
    for(int j=i+1;j<=min(i+k,n-1);++j){
      dp[j]=min(dp[j], dp[i]+abs(h[i]-h[j]));
    }
  }
  cout<<dp[n-1]<<"\n";
  return 0;
}