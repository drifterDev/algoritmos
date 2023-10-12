// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define len(str) ((int) str.length())
const int N = 1e5; // Tamaño del automata
const int ALPHA = 255; // Tamaño del alfabeto ASCII
int automata[N][ALPHA]; // Tabla de transición del automata

void kmp_automata(string& s){
  automata[0][s[0]] = 1;
  for(int i = 1, j = 0; i <= len(s); ++i){
    // Copiar la fila anterior
    for(int k = 0; k < ALPHA; ++k)automata[i][k] = automata[j][k];
    // Actualizar la entrada correspondiente al caracter actual
    if(i<len(s)){
      automata[i][s[i]]=i+1;
      j=automata[j][s[i]];
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;cin>>s;
  kmp_automata(s);
  return 0;
}
