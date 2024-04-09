// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
vector<long long> ropes;
long long k;
int n;

bool f(double x){
    long long act=0;
    for(auto r:ropes){
        act+=floor(r/x);
    }
    return act>=k;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout<<setprecision(10)<<fixed;
    cin>>n>>k;
    ropes.assign(n, 0);
    for(int i=0;i<n;++i)cin>>ropes[i];
    double l=1e-6,r=1e10;
    while(r-l>1e-7){
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
