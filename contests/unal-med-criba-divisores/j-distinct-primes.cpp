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
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;


void criba(vi& lista, vi& luckies,int tope){
  for(int i=2;i<=tope;i++){
    if(lista[i]==0){
      // *2
      for(int k=2;k*i<=tope;k++)lista[k*i]++;
    }else if(lista[i]>=3){
      luckies.push_back(i);
    }
  }
  // for(int i=0;i<sz(luckies);i++){
  //  cout<<luckies[i]<<" "; 
  // }
  //   cout<<"\n";
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
ll p,t,n=pow(10,4);cin>>t;
vi crib(n+1, 0);vi luckies;
criba(crib, luckies, n);
while(t--){
  cin>>p;cout<<luckies[p-1]<<"\n";
}
//cout<<"Lon: "<<sz(luckies)<<"\n";
return 0;}