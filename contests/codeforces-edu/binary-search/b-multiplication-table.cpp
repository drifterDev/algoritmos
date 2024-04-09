// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
long long n,k;

bool f(long long x){
    long long act=0;
    for(long long i=1;i<=n;++i){
        if(i>x)break;
        act+=min(x/i, n);
    }
    return act>=k;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n>>k;
    long long l=0,r=1e10+1;
    while(l<=r){
        long long m=l+(r-l)/2;
        if(f(m)){
            r=m-1;
        }else{
            l=m+1;
        }
    }
    cout<<r+1<<"\n";
    return 0;
}
