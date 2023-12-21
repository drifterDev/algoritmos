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

// O(n)
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
int n=len(s);
vi pi=prefix_function(s);
map<int, int> mp;
for(int i=0;i<n;i++){
  mp[pi[i]]++;
  // cout<<pi[i]<<" ";
}
if(pi[n-1]!=0){
  if(mp[pi[n-1]]>=2) cout<<s.substr(0, pi[n-1])<<"\n";
  else if(pi[pi[n-1]-1]!=0)cout<<s.substr(0,pi[pi[n-1]-1])<<"\n";
  else cout<<"Just a legend\n";
}else{
  cout<<"Just a legend\n";
}
return 0;
}