// TODO: poner el cabezado

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
  int a = 5; // Representación binaria: 0101
  int b = 3; // Representación binaria: 0011
  int resultado_and = a & b; // Resultado: 0001 (1 en decimal)
  cout << "Resultado de la operación AND: " << resultado_and << "\n";

  int resultado_or = a | b; // Resultado: 0111 (7 en decimal)
  cout << "Resultado de la operación OR: " << resultado_or << "\n";

  int resultado_xor = a ^ b; // Resultado: 0110 (6 en decimal)
  cout << "Resultado de la operación XOR: " << resultado_xor << "\n";


  int num = 42; // Representación binaria: 00101010
  // Crear un objeto bitset a partir del número
  bitset<8> bits(num);
  cout << "Secuencia de bits: " << bits << "\n";
  cout << "Cantidad de bits activados: " << bits.count() << "\n";
  // Modificar ciertos bits
  bits.set(3, true); // Establecer el cuarto bit en 1
  bits.reset(6);     // Establecer el séptimo bit en 0
  cout << "Secuencia de bits modificada: " << bits << "\n";
  return 0;
}