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

// Devuelve el arreglo de matches
const int MAX=2e5+9;
int pi[MAX];
// Pasar d el arreglo
void kmp_vi(string& t, string& s, int *d){
	pi[0]=0;int m=len(t),n=len(s);
	for(int i=1,k=0;i<m;i++){
		while(k>0 && t[k]!=t[i])k=pi[k-1];
		if(t[i]==t[k])k++;
		pi[i]=k;
	}
	for(int i=0,k=0;i<n;i++){
		while(k>0 && t[k]!=s[i])k=pi[k-1];
		if(s[i]==t[k])k++;
		d[i]=k;
		if(k==m)k=pi[k-1];
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