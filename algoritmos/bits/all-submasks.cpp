// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int m=14; // 1110
    // Todos los subconjuntos del conjunto O(2^n)
    for(int s=m;;s=(s-1)&m){
        cout<<bitset<4>(s)<<"\n";
        if(s==0)break;
    }
    // Ascendente
    for(int s=0;s=s-m&m;){ 
        cout<<bitset<4>(s)<<"\n";
        if(s==m)break;
    }

    // O(n^3)
    // for(int s=0;s<(1<<n);++s)
    //      for(submask)
    return 0;
}