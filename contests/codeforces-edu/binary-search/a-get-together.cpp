// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
vector<double> x,v;
int n;

bool f(double t){
    double l=x[0]-t*v[0];
    double r=x[0]+t*v[0];
    for(int i=1;i<n;++i){
        l=max(l, x[i]-t*v[i]);
        r=min(r, x[i]+t*v[i]);
    }
    return l<r;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout<<setprecision(10)<<fixed;
    cin>>n;
    x.assign(n, 0.0);
    v.assign(n, 0.0);
    for(int i=0;i<n;++i)cin>>x[i]>>v[i];
    double l=0,r=1e10;
    while(r-l>1e-6){
        double m=l+(r-l)/2;
        if(f(m)){
            r=m;
        }else{
            l=m;
        }
    }
    cout<<r<<"\n";
    return 0;
}
