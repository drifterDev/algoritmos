// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
int anagram[]={2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 113, 131, 199, 311, 337, 373, 733, 919, 991};

int calculate(ll n){
  int pot=floor(log10(n))+1;
  for(const auto &i:anagram){
    if(n<i && i<pow(10,pot))return i;
  }return 0;
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
ll n;cin>>n;
while(n!=0){
  if(n>991)cout<<"0\n";
  else{
    cout<<calculate(n)<<"\n";
  }
  cin>>n;
}
return 0;
}