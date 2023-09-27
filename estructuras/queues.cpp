// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    queue<int> q;
    q.push(2); //[2]
    q.push(5); //[2,5]
    cout<<q.front()<<"\n"; //5
    q.pop(); //[5]
    cout<<q.front()<<"\n"; //5
    return 0;
}