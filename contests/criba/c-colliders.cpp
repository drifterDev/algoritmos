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


void criba(vector<vi>& lista, int tope){
  for(int i=2;i<=tope;i++){
    if(sz(lista[i])==0){
      for(int k=2;k*i<=tope;k++)lista[k*i].push_back(i);
    }
  }
  // for(int i=0;i<=tope;i++){
  //   cout<<i<<" = ";
  //   for (const int &elemento:lista[i])cout<<elemento<<" ";
  //   cout<<"\n";
  // }
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
ll n,m;cin>>n>>m;
unordered_map<int, bool> nums;
unordered_map<int,int> factores;
vector<vi> crib(n+1, vi());
criba(crib, n);
char ord;int index;
while(m--){
  cin>>ord>>index;
  if (ord=='+'){
    if(nums[index])cout<<"Already on\n";
    else{
      vi comprobar = crib[index];comprobar.push_back(index);
      bool good=true;int cof;
      for (const int& elemento : comprobar) {
        if(factores[elemento]!=0){
          good=false;cof=factores[elemento];break;
        }
      }
      if (good){
        cout<<"Success\n";
        nums[index]=true;
        for(const int& facto:comprobar)factores[facto]=index;
      }else{
        cout<<"Conflict with "<<cof<<"\n";
      }
    }
  }else{
    if(!nums[index])cout<<"Already off\n";
    else{
      nums[index]=false;
      vi eliminar=crib[index];
      for(const int &el:eliminar)factores[el]=0;
      factores[index]=0;
      cout<<"Success\n";
    }
  }
}
return 0;}