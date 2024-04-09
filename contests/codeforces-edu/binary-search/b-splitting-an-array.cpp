// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
int k,n;

bool f(long long suma){
    if(a[0]>suma)return false;
    long long act=a[0];
    int k2=1;
    for(int i=1;i<n;++i){
        if(a[i]>suma)return false;
        if(act+a[i]>suma){
            k2++;
            act=0;
        }
        act+=a[i];
    }
    return k2<=k;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n>>k;
    a.assign(n,0);
    for(int i=0;i<n;++i)cin>>a[i];
    long long l=0,r=1e15;
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
