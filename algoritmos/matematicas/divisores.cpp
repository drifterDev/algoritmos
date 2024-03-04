// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) x.size())
#define S second
#define F first
typedef long long ll;

void primeFactors(ll x, map<ll,int>& f){
  for(ll i=2;i*i<=x;i++)
    while(x%i==0){
      f[i]++;
      x/=i;
    }
  if(x>1)f[x]++;
}

ll binpow(ll a, ll b, ll m){  
  ll res=1;a%=m;
  while(b>0){
    if(b&1)res=(res*a)%m;
    a=(a*a)%m;
    b>>=1;
  }
  return res%m;
}

// d(n) = (a1+1)*(a2+1)*...*(ak+1)
ll numDiv(ll n){
  ll ans=1;
  map<ll, int> f;
  primeFactors(n,f);
  for(auto &x:f)ans*=(x.S+1);
  return ans;
}

// sigma(n) = (p1^(a1+1)-1)/(p1-1) * (p2^(a2+1)-1)/(p2-1) * ... * (pk^(ak+1)-1)/(pk-1)
ll sumDiv(ll n){
  ll ans=1;         
  map<ll, int> f;
  primeFactors(n,f);
  for(auto &x:f)
    ans*=(binpow(x.F,x.S+1,LONG_LONG_MAX)-1)/(x.F-1);
  return ans;
}

ll productDiv(ll n){
  // Implementar binpow
  ll ans=numDiv(n);
  return binpow(n,ans/2,LONG_LONG_MAX);
}

// Si a y b son coprimos, entonces: 
// sigma(a*b) = sigma(a)*sigma(b)
// d(a*b) = d(a)*d(b)
