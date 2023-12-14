// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  int a=5; // Representación binaria: 0101
  int b=3; // Representación binaria: 0011
  int resultado_and=a&b; // Resultado: 0001 (1 en decimal)
  cout<<"Operación AND: "<<resultado_and<<"\n";
  int resultado_or=a|b; // Resultado: 0111 (7 en decimal)
  cout<<"Operación OR: "<<resultado_or<<"\n";
  int resultado_xor=a^b; // Resultado: 0110 (6 en decimal)
  cout<<"Operación XOR: "<<resultado_xor<<"\n";
  int resultado_not=~a; // Resultado: -a-1 (en decimal)
  cout<<"Operación NOT: "<<resultado_not<<"\n";


  int num = 42; // Representación binaria: 00101010
  // Crear un objeto bitset a partir del número
  bitset<8> bits(num);
  cout<<"Secuencia bits: "<<bits<<"\n";
  cout<<"Bits activados: "<<bits.count()<<"\n";
  cout<<"Bits desactivados: "<<bits.size()-bits.count()<<"\n";
  // Modificar ciertos bits
  bits.set(3, true); // Establecer el cuarto bit en 1
  bits.reset(6);     // Establecer el séptimo bit en 0
  cout << "Secuencia de bits modificada: " << bits << "\n";

  int num2 = 42; // Representación binaria: 00101010
  num2=num2<<2; // Desplazar dos bits a la izquierda
  cout<<"Desplazamiento a la izquierda: "<<num2<<"\n";
  num2=num2>>2; // Desplazar dos bits a la derecha
  cout<<"Desplazamiento a la derecha: "<<num2<<"\n";

  int x=42; // Representación binaria: 00101010
  for(int i=31;i>=0;i--){
    if(x&(1<<i))cout<<"1"; // Está activado el bit i
    else cout<<"0";
  }
  return 0;
}