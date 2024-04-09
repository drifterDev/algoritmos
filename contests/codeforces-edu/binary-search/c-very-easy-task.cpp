// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
int x,y,n;

bool f(int time){
    time-=x;
    int act=1 + time/x + time/y;
    return act>=n;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n>>x>>y;
    if(x>y)swap(x,y);
    int l=x,r=y*n;
    while(l<=r){
        int m=l+(r-l)/2;
        if(f(m)){
            r=m-1;
        }else{
            l=m+1;
        }
    }
    cout<<min(r+1, y*n)<<"\n";
    return 0;
}
