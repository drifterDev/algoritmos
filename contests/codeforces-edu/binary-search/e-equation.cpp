// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
long double c;

long double f(long double x){
    return x*x + sqrtl(x);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout<<setprecision(10)<<fixed;
    cin>>c;
    long double l=1,r=1e5;
    while(r-l>1e-8){
        long double m=l+(r-l)/2;
        if(f(m)>=c){
            r=m;
        }else{
            l=m;
        }
    }
    cout<<r<<"\n";
    return 0;
}
