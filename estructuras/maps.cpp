// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    map<string, int> m;
    m["Mango"]=4;
    m["Fresa"]=3;
    m["Kiwi"]=9;
    cout<<m["Fresa"]<<"\n"; //3
    cout<<m["Mora"]<<"\n"; //0

    if (m.count("Mango")){
      //La llave existe
    }

    //Recorrer un map
    for(auto x:m){
      cout<<x.first<<" "<<x.second<<"\n";
    }

    // Usa hashing y es O(1), desventaja: no esta ordenado
    unordered_map<int,int> m2;

    map<int, int> m;
    m[3] = 5; // [(3, 5)]
    m[11] = 4; // [(3, 5); (11, 4)]
    m[10] = 491; // [(3, 5); (10, 491); (11, 4)]
    cout << m.lower_bound(10)->first << " " << m.lower_bound(10)->second << '\n'; //,→ 10 491
    cout << m.upper_bound(10)->first << " " << m.upper_bound(10)->second << '\n'; //,→ 11 4
    m.erase(11); // [(3, 5); (10, 491)]
    if (m.upper_bound(10) == m.end())
    {
    cout << "end" << endl; // Prints end
    }
    return 0;
}