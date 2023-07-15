// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}

const long long MOD = 1e9 + 7;
long long fastPow(long long a, long long b) {
    if (b == 0) return 1ll;
    if (b == 1) return a;
    if (b % 2 == 0) {
        long long tmp = fastPow(a, b/2);
        return (tmp * tmp) % MOD;
    } 

    return (a * fastPow(a, b-1)) % MOD;
}