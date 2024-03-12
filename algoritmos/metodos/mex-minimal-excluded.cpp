// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) x.size())
typedef vector<int> vi;

// El menor numero (0>=) que no está en un conjunto de números
struct Mex {
  map<int, int> f; // Frecuencia
  set<int> mn; // Numeros que faltan
  vi nums;

  // O(nlog(n))
  Mex(vi const& nums, int maxn) : nums(nums) {
    for(int i=0;i<=maxn+1;i++)mn.insert(i);
    for(int x:nums){
      f[x]++;
      mn.erase(x);
    }
  }

  // O(1)
  int getMex(){
    return *mn.begin();
  }

  // O(log(n))
  void add(int x){
    ++f[x];
    if(f[x]==1)mn.erase(x);
  }

  // O(log(n))
  void update(int idx, int newval){
    if(--f[nums[idx]]==0)mn.insert(nums[idx]);
    nums[idx] = newval;
    ++f[newval];
    if(f[newval]==1)mn.erase(newval);
  }
};
