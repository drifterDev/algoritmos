// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef long long ll;

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
ll c=0,k,num,sum;cin>>k;
for (ll i=2;i<= 1300000;i++) {
  num = 9 * i + 1;sum = 0;
  string numStr=to_string(num);
  for (char digit : numStr) {
      sum += digit - '0';
  }if (sum == 10)c++;
  if (c==k){
    cout<<num<<"\n";
    break;
  }
}
return 0;
}