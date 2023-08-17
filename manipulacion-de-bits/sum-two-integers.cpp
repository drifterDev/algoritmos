// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
return 0;
}

// a = 10 (binario: 1010)
// b = 6  (binario: 0110)
// a & b = 2  (binario: 0010)
// a ^ b = 12  (binario: 1100)

// n = 10 (binario: 1010)
// num << 2 = 40 (binario: 101000)
// n = 40 (binario: 101000)
// num >> 2 = 10 (binario: 1010)


class Solution {
public:
    int getSum(int a, int b) {
        // Repetir el proceso mientras haya acarreo (carry)
        while (b != 0) {
            // Calculamos el acarreo, que es la parte común entre "a" y "b"
            int carry = a & b;

            // Sumamos "a" y "b" sin tener en cuenta el acarreo
            // Esto es como sumar los dígitos de "a" y "b" en binario sin llevar
            a = a ^ b;

            // Desplazamos el acarreo un bit hacia la izquierda para prepararlo para la siguiente suma
            b = carry << 1;
        }

        // Cuando no hay más acarreos, el resultado está en "a"
        return a;
    }
};
