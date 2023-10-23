// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(arr) arr.begin(), arr.end()

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  set<int> s;
  //Los sets son una colección de elementos unicos
  //y ordenada que nos permite realizar operaciones
  //como insertar, remover y buscar
  s.insert(3); //{3}
  s.insert(2); //{2,3}
  s.insert(5); //{5,2,3}
  cout<<s.count(3)<<"\n"; //1
  cout<<s.count(4)<<"\n"; //0
  s.erase(3);
  s.insert(4);
  cout<<s.count(3)<<"\n"; //0
  cout<<s.count(4)<<"\n"; //1
  //Podemos buscar elementos dentro del set
  ll x=99; //Elemento a buscar
  auto it=s.find(x);
  if(it==s.end()){
    //x is not found
  }
  cout<<*s.lower_bound(x)<<"\n";
  cout<<*s.upper_bound(x)<<"\n";

  //Set con multiples elementos repetidos
  multiset<int> s2;
  s2.insert(5);
  s2.insert(5);
  s2.insert(5);
  cout<<s2.count(5)<<"\n";

  //Eliminar solo uno de los elementos de un multiset
  s2.erase(s.find(5));
  cout<<s2.count(5)<<"\n"; //2

  //Eliminar todos los elementos de un multiset
  s2.erase(5);
  cout<<s2.count(5)<<"\n"; //0
  

  // Operaciones basicas de conjuntos
  vector<int>valores={20, 50, 30, 40, 50, 10};
  unordered_set<int>a;
  for(int v:valores) a.insert(v);

  unordered_set<int> b(all(valores));
  cout<<a.size()<<"\n";
  cout<<(b.find(40)!=b.end())<<"\n";

  a.erase(50);
  for(int value:a)cout<<value<<" ";
  cout<<"\n";

  unordered_set<int> c={0, 1, 1, 2, 3, 5, 8, 13, 21};
  unordered_set<int> d={2, 3, 5, 7, 11, 13, 17, 19};

  // Operaciones entre conjuntos
  cout<<"Intersection: ";
  for(int value:c){
    if(d.find(value)!=d.end())cout<<value<<" ";
  }
  cout<<"\nUnion: ";
  for(int value:c){
    cout<<value<<" ";
  }
  for(int value:d){
    cout<<value<<" ";
  }
  cout<<"\nDifference: ";
  for(int value:c) {
    if(d.find(value)==d.end())cout<<value<<" ";
  }
  cout<<"\nSymmetric Difference: ";
  for(int value:c){
    if(d.find(value)==d.end()) cout<<value<<" ";
  }
  for(int value:d) {
    if(c.find(value)==c.end())cout<<value<<" ";
  }
  cout<<"\n"<<(c<=d)<<"\n";
  return 0;
}
