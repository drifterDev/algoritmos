// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
#define len(str) ((int) str.length())
typedef vector<int> vi;

// O(t+p)
vi z_algoritm(string s){
  int n=len(s),l=0,r=0;
  vi z(n);
  for(int i=1;i<n;i++){
    z[i]=max(0, min(z[i-l], r-i+1));
    while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
      l=i,r=i+z[i],++z[i];
    }
  }
  return z;
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
string t="abababab",p="aba";
vi z=z_algoritm(p+"$"+t);
cout<<"Algoritmo z:\n";
for(int i=0;i<sz(z);i++){
if(z[i]==len(p))cout<<i-len(p)-1<<" ";
}cout<<"\n";
return 0;
}