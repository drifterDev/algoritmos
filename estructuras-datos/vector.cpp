// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n=9;
    //Array tamaño fijo
    int array[n];
    int array[n][n];
    bool array[2][n][n];
    //Vector tamaño dinamico
    vector<int> v(n);

    v.push_back(4);
    v.pop_back();
    v.resize(n*n);
    v.assign(n, 5);

    vector<int> v2={1,2,4,54,3,5};
    //Eliminar o agregar un elemento al final es O(1)

    v.size(); //Tamaño
    v.back(); //Ultimo

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    lower_bound(v.begin(), v.end(), 5);
    upper_bound(v.begin(), v.end(), 5);

    for(int i=0;i<v.size();i++){
      cout<<v[i]<<"\n";
    }

    for(auto x: v){
      cout<<x<<"\n";
    }
    return 0;
}