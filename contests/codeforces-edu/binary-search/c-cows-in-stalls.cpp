// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
vector<int> d;
int n,k;

bool f(int x){
    int tmp=d[0];
    int k2=1;
    for(int i=1;i<n;++i){
        if(d[i]-tmp>=x){
            tmp=d[i];
            k2++;
        }
    }
    return k2>=k;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n>>k;
    d.assign(n,0);
    for(int i=0;i<n;++i)cin>>d[i];
    int l=0,r=1e9;
    while(l<=r){
        int m=l+(r-l)/2;
        if(f(m)){
            l=m+1;
        }else{
            r=m-1;
        }
    }
    cout<<max(0,l-1)<<"\n";
    return 0;
}
