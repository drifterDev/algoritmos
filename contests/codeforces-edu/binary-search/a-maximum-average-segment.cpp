// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int n,d,x1,x2;

bool f(long double x){
    vector<long double> p(n+1,0);
    for(int i=1;i<=n;++i){
        p[i]=p[i-1]+(a[i-1]-x);
    }

    vector<pair<long double,int>> mini(n,{0,1});
    for(int i=1;i<n;++i){
        if(mini[i-1].first<p[i]){
            mini[i]=mini[i-1];
        }else{
            mini[i]={p[i], i+1};
        }
    }

    for(int l=1;d-1+l<=n;++l){
        int r=d-1+l;
        if(p[r]>=mini[l-1].first){
            x1=mini[l-1].second;
            x2=r;
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n>>d;
    a.assign(n,0);
    for(int i=0;i<n;++i)cin>>a[i];
    long double l=0,r=1e2;
    while(r-l>=1e-7){
        long double m=l+(r-l)/2;
        if(f(m)){
            l=m;
        }else{
            r=m;
        }
    }
    f(l);
    cout<<x1<<" "<<x2<<"\n";
    return 0;
}
