// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
long long k;
int n;

bool f(long long x){
    long long tmp = k * x;
    for(auto ai:a){
        tmp-=min(ai, x);
    }
    return tmp<=0;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>k>>n;
    a.assign(n,0);
    for(int i=0;i<n;++i)cin>>a[i];
    long long l=1,r=1e11;
    while(l<=r){
        long long m=l+(r-l)/2;
        if(f(m)){
            l=m+1;
        }else{
            r=m-1;
        }
    }
    cout<<max(1ll, l-1)<<"\n";
    return 0;
}
