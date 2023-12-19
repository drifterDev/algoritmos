// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
#define all(x) x.begin(), x.end()
typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // Para minimizar la suma de 
  // |a1 − x| +|a2 − x| +··· +|an − x|
  // Escogemos la mediana
  vi nums={1,9,2,6,2};
  sort(all(nums));
  int res=0, n=sz(nums)/2;
  for(int x:nums)res+=abs(x-nums[n]);
  cout<<res<<"\n";

  // Para minimizar la suma de
  // (a1 − x)^2 +(a2 − x)^2 +··· +(an − x)^2
  // Escogemos la media
  int media=0;
  for(int x:nums)media+=x;
  media/=sz(nums);
  int res2=0;
  for(int x:nums)res2+=pow((x-media),2);
  cout<<res2<<"\n";
  return 0;
}