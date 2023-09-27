// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    deque<int> d;
    d.push_back(5); //[5]
    d.push_back(2); //[5,2]
    d.push_front(3); //[3,5,2]
    d.pop_back(); //[3,5]
    d.pop_front(); //[5]
    return 0;
}