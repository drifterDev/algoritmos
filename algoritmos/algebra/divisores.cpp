// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// O(sqrt(n))
ll numberOfDivisors(ll num){
  ll total=1;
  for(int i=2;(ll)i*i<=num;i++){
    if (num%i==0){
      int e=0;
      do{
        e++;
        num/=i;
      }while(num%i==0);
      total*=e+1;
    }
  }
  if(num>1) total *= 2;
  return total;
}

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}