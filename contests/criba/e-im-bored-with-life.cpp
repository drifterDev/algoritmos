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
ll a,b;cin>>a>>b;
ll facto=1, mini=min(a,b);
for (int i=2;i<=mini;i++)facto*=i;
cout<<facto<<"\n";
return 0;
}