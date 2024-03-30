// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
#define len(str) ((int) str.length())
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
 
// O(n)
vi z_function(string s) {
  int n=len(s),l=0,r=0;
  vi z(n);
  for(int i=1;i<n;i++){
    if(i<r)z[i]=min(r - i, z[i - l]);
    while(i+z[i]<n && s[z[i]]==s[i+z[i]])z[i]++;
    if(i+z[i]>r){
      l=i;
      r=i+z[i];
    }
  }
  return z;
}
 
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
string s;cin>>s;
vi z=z_function(s);
vi res;int n=len(s);
for(int i=1;i<n;i++){
  // cout<<z[i]<<" ";
  if(z[i]+i==n){
    res.push_back(i);
  }
}
for(int i:res){
  cout<<i<<" ";
}cout<<n<<"\n";
return 0;
}