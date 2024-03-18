// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
typedef vector<int> vi;

// O(nlogn)
// si es <= usar upper_bound y el primer < en el if ponerlo <=
int lis(vi& nums){
  int n=sz(nums);
  vi dp(n+1,INT_MAX),cnt(n,0);
  dp[0]=INT_MIN;
  int last=0;

  for(int i=0;i<n;++i){
    int j=lower_bound(all(dp), nums[i])-dp.begin();
    if(dp[j-1]<nums[i] && nums[i]<dp[j]){
      dp[j]=nums[i];
      last=max(last,j);
    }
    cnt[i]=j;
  }

  int ans=0;
  for(int i=0;i<=n;i++){
    if(dp[i]<INT_MAX)ans=i;
  }

  // reconstruir LIS
  vi LIS(ans);
  int act=ans;
  for(int i=n-1;i>=0;--i){
    if(cnt[i]==act){
      LIS[act-1]=nums[i];
      act--;
    }
  }

  return ans;
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  // freopen("file.in", "r", stdin);
  // freopen("file.out", "w", stdout);
  int n;cin>>n;
  vi nums(n);
  for(int i=0;i<n;++i)cin>>nums[i];
  cout<<lis(nums)<<"\n";
  return 0;
}