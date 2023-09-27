// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int MAX = 15;
int catalan[MAX];

// O(n^2)
void init() {
    catalan[0] = catalan[1] = 1;
    for (int i=2; i<MAX; i++) {
        catalan[i] = 0;
        for (int j=0; j < i; j++) {
            catalan[i] += (catalan[j] * catalan[i-j-1]) % MOD;
            if (catalan[i] >= MOD) {
                catalan[i] -= MOD;
            }
        }
    }
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
init(); 
// Visualizar
for (int i = 0; i < MAX; i++) cout<<"Catalan["<<i<<"] = "<<catalan[i]<<"\n";
return 0;
}