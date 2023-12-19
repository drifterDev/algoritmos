// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define F first
#define S second
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // pares.F = duracion
  // pares.S = tiempo limite
  vii pares={{4,2},{3,5},{2,7},{4,5}};
  int n=4;
  // Hay que mirar las tareas que acaben primero, sin importar su tiempo limite
  // Suena raro no tener en cuenta el tiempo limite, pero se puede demostrar
  // La razón de esto es que si alguna vez
  // realizamos dos tareas una tras otra de modo que la primera tarea demore más que la
  // segunda, podemos obtener una mejor solución si intercambiamos las tareas.
  sort(all(pares));
  int act=0,res=0;
  for(auto x:pares){
    act+=x.F;
    res+=(x.S-act);
  }cout<<res<<"\n";
return 0;
}