// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
long long a,b,n;

bool f(long long x){
    long long act = (x/a) * (x/b);
    return act>=n;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>a>>b>>n;
    long long l=0,r=1;
    while(!f(r))r*=2;
    long long r2=r;
    while(l<=r){
        long long m=l+(r-l)/2;
        if(f(m)){
            r=m-1;
        }else{
            l=m+1;
        }
    }
    long long res=min(r2, r+1);
    cout<<res<<"\n";
    return 0;
}
