// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; 
// Para multiset cambiar less<int> por less_equal<int>
// tree.find_by_order(k) -> Retorna un iterador al k-ésimo elemento 
// tree.order_of_key(x) -> Retorna el número de elementos estrictamente menores a x

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  // freopen("file.in", "r", stdin);
  // freopen("file.out", "w", stdout);
  ordered_set s;
  s.insert(1);
  s.insert(3);
  s.insert(5);
  s.insert(7);
  s.insert(9);
  cout<<*s.find_by_order(4)<<"\n"; //9
  cout<<s.order_of_key(7)<<"\n"; //3
  cout<<s.order_of_key(8)<<"\n"; //4
  cout<<s.order_of_key(11)<<"\n"; //5
  return 0;
}