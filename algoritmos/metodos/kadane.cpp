// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) x.size())
typedef vector<int> vi;

// O(n)
int kadane(vi &nums){
  int n=sz(nums);
  int ans=nums[0],sum=nums[0];
  for(int i=1;i<n;++i){
    sum=max(nums[i],sum+nums[i]);
    ans=max(ans,sum);
  }
  return ans;
}