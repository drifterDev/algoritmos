// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
vector<int> a;
string t,p;
int n,m;

bool f(int x){
    vector<bool> can(n,true);
    for(int i=0;i<x;++i){
        can[a[i]-1]=false;
    }
    for(int i=0,j=0;i<n;++i){
        if(!can[i])continue;
        if(t[i]==p[j]){
            j++;
        }
        if(j==m)return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>t>>p;
    n=t.size(),m=p.size();
    a.assign(n,0);
    for(int i=0;i<n;++i)cin>>a[i];
    int l=0,r=n;
    while(l<=r){
        int m=l+(r-l)/2;
        if(f(m)){
            l=m+1;
        }else{
            r=m-1;
        }
    }
    cout<<max(0, l-1)<<"\n";
    return 0;
}
