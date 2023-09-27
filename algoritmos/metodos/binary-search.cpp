// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

// O(log(n))
int binary_search(vi& nums, int target) {
  int l=0,r=nums.size()-1;
  while(l<=r) {
    int m=l+(r-l)/2;
    if (nums[m]==target)return m;
    if (nums[m]<target)l=m+1;
    else r=m-1;
  }return -1;
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
return 0;
}