// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define PB push_back
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
vector<char> tasks={'A','B','C','D'};
vi begins={1,2,3,6};
vi times={3,5,9,8};
vii ends;
int n=sz(tasks), actualTime=0;
for(int i=0;i<n;++i)ends.PB({begins[i]+times[i],i});
sort(all(ends));
for(auto act:ends){
  // Buscamos la tarea que termine primero
  int task=act.S;
  if(actualTime<=begins[task]){
    cout<<"Tarea "<<tasks[task]<<" de "<<begins[task]<<" a "<<begins[task]+times[task]<<"\n";
    actualTime=begins[task]+times[task];
  }
}
return 0;
}