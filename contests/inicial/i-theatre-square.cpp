// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <iostream>
#include <cmath>
using namespace std;
int main() {
  long long a, b, c;
  cin>>a >>b >>c;
  long long resultado,sum1,sum2,n1,n2;
  if (a%c==0){
    n1=0;
  }else{
    n1=1;
  }
  if (b%c==0){
    n2=0;
  }else{
    n2=1;
  }
  sum1=floor(a/c)+n1;
  sum2=ceil(b/c)+n2;
  resultado = sum1 * sum2 ;
  cout<<resultado;
}