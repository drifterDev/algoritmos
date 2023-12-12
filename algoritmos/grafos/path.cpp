// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define PB push_back
typedef vector<int> vi;
int n;

vi find_path(int a, int b, vi& p){
  vi path;
  for(int v=b;v!=a;v=p[v]){
    path.PB(v);
  }
  path.PB(a);
  reverse(all(path));
  return path;
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  n=5;
  vi p(n);
  p[1]=0;
  p[3]=1;
  p[4]=3;
  p[2]=4;
  p[0]=-1;
  vi pa=find_path(0,2,p);
  for(auto u:pa)cout<<u<<" ";
  return 0;
}