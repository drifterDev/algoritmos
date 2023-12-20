// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define S second
#define F first
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
int n; // cantidad de elementos
int w; // capacidad 

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  cin>>n>>w;
  vii weights(n); // F weight, S value
  for(int i=0,tmp;i<n;++i){cin>>tmp;weights[i]={tmp,0};}
  for(int i=0;i<n;++i)cin>>weights[i].S;
  vector<vi> dp(n+1,vi(w+1,0));
  for(int i=0;i<=n;++i)dp[i][0]=0;
  for(int i=0;i<=w;++i)dp[0][i]=0;
  for(int i=1;i<=n;++i){
    for(int j=0;j<=w;++j){
      dp[i][j]=dp[i-1][j];
      if(j<weights[i-1].F)continue;
      dp[i][j]=max(dp[i][j],weights[i-1].S+dp[i-1][j-weights[i-1].F]);
    }
  }
  cout<<dp[n][w]<<"\n";
  return 0;
}