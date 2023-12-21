// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout<<#x<<"="<<x<<'\n'
#define trace(x) cerr<<#x<<"="<<x<<'\n'
#define sz(arr) ((int) arr.size())
#define all(x) x.begin(), x.end()
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;
ll dp[100000][102];
 
int main() {
ios::sync_with_stdio(false);
cin.tie(0);
int n,m;cin>>n>>m;
vi nums(n);
for(int i=0;i<n;i++)cin>>nums[i];
if(nums[0]==0)for(int i=1;i<=m;i++)dp[0][i]=1;
else dp[0][nums[0]]=1;
 
for(int i=1;i<n;i++){
  if(nums[i]==0){
    for(int j=1;j<m+1;j++){
      dp[i][j]=(dp[i-1][j-1]%MOD);
      dp[i][j]+=(dp[i-1][j]%MOD);
      dp[i][j]+=(dp[i-1][j+1]%MOD);
    }
  }else{
    dp[i][nums[i]]=((dp[i-1][nums[i]-1]%MOD)+(dp[i-1][nums[i]]%MOD)+(dp[i-1][nums[i]+1]%MOD))%MOD;
  }
}
 
// for(int i=0;i<n;i++){
//   for(int j=0;j<m+2;j++){
//     cout<<dp[i][j]<<" ";
//   }cout<<"\n";
// }
 
if(nums[n-1]!=0)cout<<dp[n-1][nums[n-1]]%MOD<<"\n";
else{
  ll res=0;
  for(int i=1;i<m+1;i++)res+=(dp[n-1][i]%MOD);
  cout<<res%MOD<<"\n";
}
return 0;
}