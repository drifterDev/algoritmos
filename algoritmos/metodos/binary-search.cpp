// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define all(x) x.begin(), x.end()

// O(log(n))
int binary_search(vi& nums, int target) {
  int l=0,r=nums.size()-1;
  while(l<=r) {
    int m=(l+r)/2;
    if (nums[m]==target)return m;
    if (nums[m]<target)l=m+1;
    else r=m-1;
  }return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vi v={1, 2, 4, 4, 5, 6, 7, 8, 9};
  int x=6;
  auto lower=lower_bound(all(v),x);
  auto upper=upper_bound(all(v),x);
  int indexLower=distance(v.begin(),lower);
  int indexUpper=distance(v.begin(),upper);
  cout<<"Lower Bound de "<<x<<" en el índice: "<<indexLower<<"\n";
  cout<<"Lower Bound de "<<x<<": "<<*lower<<"\n";
  cout<<"Upper Bound de "<<x<<" en el índice: "<<indexUpper<<"\n";
  cout<<"Upper Bound de "<<x<<": "<<*upper<<"\n";
  return 0;
}