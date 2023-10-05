// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
#define len(str) ((int) str.length())
#define all(x) x.begin(), x.end()
typedef vector<string> vs;
typedef vector<int> vi;


vi prefix_function(string s){
  int n=len(s);
  vi pi(n);
  for(int i=1;i<n;i++) {
    int j=pi[i-1];
    while(j>0 && s[i]!=s[j])j=pi[j-1];
    if (s[i]==s[j])j++;
    pi[i]=j;
  }
  return pi;
}

// O(|t| + |p|)
int matches=0;
void kmp(string &t, string &p){ 
  vi phi=prefix_function(p);
  for(int i=0,j=0;i<sz(t);i++){
    while(j>0 && t[i]!=p[j])j=phi[j-1];
    if(t[i]==p[j])j++;
    if(j==sz(p)){
      cout<<i-j+1<<" "; // Posición de la ocurrencia
      matches++;
      j=phi[j-1];
    }
  }
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
string t="aabaaab";
string p="aab";
cout<<"Ocurrencias\n";
kmp(t,p);
cout<<"\nCantidad de matches\n";
cout<<matches<<'\n';
return 0;
}