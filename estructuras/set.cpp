// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(arr) arr.begin(), arr.end()

bool comp(const int& a, const int& b){
    // Funcion de comparacion personalizada
}

int main() {
    set<int, decltype(comp)*> setPersonalizado;
    set<int> s;
    s.insert(3); 
    s.erase(3);
    s.insert(4); 
    cout<<s.count(3)<<"\n"; //1
    int x=3;
    cout<<*s.lower_bound(x)<<"\n"; // *it >= x
    cout<<*s.upper_bound(x)<<"\n"; // *it > x

    //Set con multiples elementos repetidos
    multiset<int> s2;
    s2.insert(5);
    s2.insert(5);
    s2.insert(5);
    cout<<s2.count(5)<<"\n"; // 3

    // Eliminar solo uno de los elementos de un multiset
    s2.erase(s2.find(5));
    cout<<s2.count(5)<<"\n"; // 2

    // Eliminar todos los elementos de un multiset
    s2.erase(5);
    cout<<s2.count(5)<<"\n"; // 0
    

    // Ventaja O(1), Desventaja desordenado
    unordered_set<int> c={0, 1, 1, 2, 3, 5, 8, 13, 21};
    unordered_set<int> d={2, 3, 5, 7, 11, 13, 17, 19};

    // Operaciones entre conjuntos
    cout<<"Intersection: ";
    for(int value:c)if(d.find(value)!=d.end())cout<<value<<" ";
    
    cout<<"\nUnion: ";
    for(int value:c)cout<<value<<" ";
    for(int value:d)cout<<value<<" ";
    
    cout<<"\nDifference: ";
    for(int value:c)if(d.find(value)==d.end())cout<<value<<" ";
    
    cout<<"\nSymmetric Difference: ";
    for(int value:c)if(d.find(value)==d.end()) cout<<value<<" ";
    for(int value:d)if(c.find(value)==c.end())cout<<value<<" ";

    return 0;
}
