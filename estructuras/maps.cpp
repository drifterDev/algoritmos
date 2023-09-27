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

    unordered_map<int,int> m2;
    return 0;
}