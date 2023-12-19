// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

// Función que calcula el número de cuadrados en una diagonal de un tablero
int squares(int i){
  if (i&1)return i/4*2+1;
  else return(i-1)/4*2+2;
}

// Función para contar el número de formas de colocar K alfiles en un tablero de ajedrez NxN
int bishop_placements(int N, int K){
  if (K>2*N-1)return 0;
  vector<vi> D(N*2,vi(K+1));
  for(int i=0;i<N*2;i++)D[i][0]=1;
  D[1][1]=1;

  for(int i=2;i<N*2;i++)
      for(int j=1;j<=K;j++)
          D[i][j]=D[i-2][j]+D[i-2][j-1]*(squares(i)-j+1);

  int ans=0;
  for(int i=0;i<=K;i++)ans+=D[N*2-1][i]*D[N*2-2][K-i];
  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N = 4; // Tamaño del tablero
  int K = 3; // Número de alfiles
  // O(k*n^2)
  int result=bishop_placements(N, K);
  cout<<"Número de formas de colocar "<<K<<" alfiles en un tablero "<<N<<"x"<<N<<": "<<result<<"\n";
  return 0;
}
