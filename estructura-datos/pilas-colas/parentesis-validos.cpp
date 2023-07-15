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

// O(n)
bool isValid(string s){
  stack<char> pila;
  for (char& caracter: s){
    if (caracter==')'){
      if(pila.empty()){
        return false;
      }
      pila.pop();
    }else if(caracter=='('){
      pila.push(caracter);
    }
  }
  return pila.empty();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}