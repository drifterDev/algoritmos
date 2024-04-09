// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
vector<int> a,b;
long long k;
int n;

bool f(int suma){
    long long act=0;
    for(int i=0;i<n;++i){
        if(a[i]>suma)break;
        auto it=upper_bound(b.begin(), b.end(), suma-a[i]);
        act+=distance(b.begin(), it);
    }
    return act>=k;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n>>k;
    a.assign(n,0);
    b.assign(n,0);
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i)cin>>b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int l=0,r=2*1e9+1;
    while(l<=r){
        int m=l+(r-l)/2;
        if(f(m)){
            r=m-1;
        }else{
            l=m+1;
        }
    }
    cout<<r+1<<"\n";
    return 0;
}
