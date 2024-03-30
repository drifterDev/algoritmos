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
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

ll valor(ll x){
  if (x%2==0){
    return (x/2)+(x*(x/2)); 
  }else{
    return x*((x+1)/2);
  }
}

ll busquedaBinaria(ll n, ll k){
  ll mid,left=0,right=pow(10,9);
  while(left<=right){
    mid=left+(right-left)/2;
    if(valor(mid)-k==n-mid)return n-mid;
    else if(valor(mid)-k<n-mid) left=mid+1;
    else right=mid-1;
  }
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
ll n,k;cin>>n>>k;
cout<<busquedaBinaria(n,k)<<"\n";
return 0;
}