// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long n, x, entrada;
    cin >> n >> x;
    vector<long long> array;
    for (long long i = 0; i < n; i++) {
        cin >> entrada;
        array.push_back(entrada);
    }
    long long low, high, mid, index;
    index=-1;
    low=0;
    high=array.size()-1;
    while (low<=high){
      mid=(low+high)/2;
      if (array.at(mid)==x){
        index=mid;
        break;
      }else if(array.at(mid)>x){
        high=mid-1;
      }else{
        low=mid+1;
      }
    }
    cout<<index<<"\n";
    return 0;
}





