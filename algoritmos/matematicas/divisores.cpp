// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef long long ll;

// O(sqrt(n))
ll SumOfDivisors(ll num){
  ll total=1;
  for(int i=2;(ll)i*i<=num;i++){
    if (num % i == 0){
      int e = 0;
      do{
        e++;num /= i;
      }while(num%i==0);
      ll sum=0,pow=1;
      do{
        sum += pow;pow *= i;
      } while(e-->0);
      total*=sum;
    }
  }
  if(num>1) total *= (1 + num);
  return total;
}

// O(sqrt(n)) pero con los primos precalculados
ll numDiv(ll n){
  ll ans=1;
  for(int i=0;(i<sz(p))&&(p[i]*p[i]<=n);++i){
    int power=0;
    while(n%p[i]==0){n/=p[i];++power;}
    ans*=power+1;
  }
  return(n!= 1)?2*ans:ans;
}

// O(sqrt(n)) pero con los primos precalculados
ll sumDiv(ll n){
  ll ans=1;         
  for(int i=0;(i<sz(p))&&(p[i]*p[i]<=n);++i){
    ll multiplier=p[i],total=1;
    while(n%p[i]==0){
      n/=p[i];
      total+=multiplier;
      multiplier*=p[i];
    }                                  
    ans*=total;                       
  }
  if(n!= 1)ans*=(n+1);
  return ans;
}

ll productDiv(ll n){
  // Implementar binpow
  ll ans=numDiv(n);
  return binpow(n,ans/2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}