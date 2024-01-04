// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) x.size())
typedef vector<int> vi;

int kadane(vi &nums){
  int n=sz(nums);
  int ans=nums[0],sum=nums[0];
  for(int i=1;i<n;++i){
    sum=max(nums[i],sum+nums[i]);
    ans=max(ans,sum);
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
  cout<<kadane(nums)<<"\n";
  return 0;
}