// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
const int INF = 1e9;

// O(nlogn)
int lis(vi& nums){
  int n=sz(nums);
  vi dp(n+1,INF);
  dp[0]=-INF;
  for(int i=0;i<n;++i){
    int j=upper_bound(all(dp), nums[i])-dp.begin();
    if(dp[j-1]<nums[i] && nums[i]<dp[j])dp[j]=nums[i];
  }
  int ans=0;
  for(int i=0;i<=n;i++){
    if(dp[i]<INF)ans=i;
  }
  return ans;
}