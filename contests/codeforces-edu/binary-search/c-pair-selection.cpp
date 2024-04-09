// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
vector<double> a,b;
int n,k;

bool f(double x){
    vector<double> p(n,0);
    for(int i=0;i<n;++i){
        p[i]=a[i]-x*b[i];
    }
    sort(p.rbegin(), p.rend());
    double suma=0;
    for(int i=0;i<k;++i)suma+=p[i];
    return suma>=0;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout<<setprecision(8)<<fixed;
    cin>>n>>k;
    a.assign(n,0);
    b.assign(n,0);
    for(int i=0;i<n;++i)cin>>a[i]>>b[i];
    double l=0,r=1e11;
    while(r-l>=1e-7){
        double m=l+(r-l)/2;
        if(f(m)){
            l=m;
        }else{
            r=m;
        }
    }    
    cout<<l<<"\n";
    return 0;
}
