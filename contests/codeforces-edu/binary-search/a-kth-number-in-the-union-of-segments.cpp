// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
vector<long long> l,r;
long long n,k;

bool f(long long x){
    long long act=0;
    for(long long i=0;i<n;++i){
        if(l[i]>x)continue;
        act+=min(x, r[i])-l[i]+1;
    }
    return act<=k;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n>>k;
    l.assign(n,0);
    r.assign(n,0);
    for(int i=0;i<n;++i)cin>>l[i]>>r[i];
    long long lo=-2000000000,hi=2000000000;
    while(lo<=hi){
        long long m=lo+(hi-lo)/2;
        if(f(m)){
            lo=m+1;
        }else{
            hi=m-1;
        }
    }
    cout<<lo<<"\n";
    return 0;
}
