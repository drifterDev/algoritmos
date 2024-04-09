// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
vector<long long> c,h,p;
long long r;
string s;

bool f(long long x){
    long long x1=c[0]*x;
    long long x2=c[1]*x;
    long long x3=c[2]*x;
    long long act=0;
    act+=p[0]*max(0ll, x1-h[0]);
    act+=p[1]*max(0ll, x2-h[1]);
    act+=p[2]*max(0ll, x3-h[2]);
    return act<=r;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>s;
    c.assign(3,0);
    h.assign(3,0);
    p.assign(3,0);
    for(auto x:s){
        if(x=='B')c[0]++;
        if(x=='S')c[1]++;
        if(x=='C')c[2]++;
    }
    cin>>h[0]>>h[1]>>h[2];
    cin>>p[0]>>p[1]>>p[2];
    cin>>r;
    long long l=0,r=1e13;
    while(l<=r){
        long long m=l+(r-l)/2;
        if(f(m)){
            l=m+1;
        }else{
            r=m-1;
        }
    }
    cout<<max(0ll, l-1)<<"\n";
    return 0;
}
