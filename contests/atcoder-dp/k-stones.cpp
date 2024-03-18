// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  // freopen("file.in", "r", stdin);
  // freopen("file.out", "w", stdout);
  int n,k;cin>>n>>k;
  vi nums(n);
  for(int i=0;i<n;++i)cin>>nums[i];
  vector<bool> dp(k+1,true);
  dp[0]=false;
  for(int i=1;i<=k;++i){
    bool act=true;
    for(int j=0;j<n;++j){
      if(i-nums[j]<0)continue;
      act=act && dp[i-nums[j]];
    }
    dp[i]=!act;
  }
  cout<<(dp[k]?"First":"Second")<<"\n";
  return 0;
}