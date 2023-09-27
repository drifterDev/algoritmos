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

vector<string> letterCombinations(string numeroCelular){
  unordered_map<char, string> teclado;
  teclado['2']="abc";
  teclado['3']="def";
  teclado['4']="ghi";
  teclado['5']="jkl";
  teclado['6']="mno";
  teclado['7']="pqrs";
  teclado['8']="tuv";
  teclado['9']="wxyz";
  vector<string> listaPalabras;
  generarCombinaciones(0, numeroCelular, "", listaPalabras, teclado);
  return listaPalabras;
}

void generarCombinaciones(int i, string numeroCelular, string palabra, vector<string> listaPalabras, unordered_map<char, string> teclado){
  if (i==numeroCelular.length()){
    if (palabra!=""){
      listaPalabras.push_back(palabra);
    }
    return;
  }
  for (auto letra: teclado[numeroCelular[i]]){
    generarCombinaciones(i+1, numeroCelular, palabra+letra, listaPalabras, teclado);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}