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

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
string s;cin>>s;
vi pi=prefix_function(s);
for(int i=0;i<len(s);i++)cout<<pi[i]<<" ";
cout<<"\n";
int n=len(s);
vi ans(n + 1);
for(int i=0;i<n;i++)ans[pi[i]]++;
for(int i=n-1;i>0;i--)ans[pi[i-1]]+=ans[i];
for(int i=0;i<=n;i++)ans[i]++;
for(int i=0;i<=n;i++)cout<<"El prefijo de tamaño "<<i<<" aparece "<<ans[i]<<" veces\n";
return 0;
}