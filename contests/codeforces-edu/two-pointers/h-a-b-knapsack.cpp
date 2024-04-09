// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    long long s,a_,b_,n,m;
    cin>>n>>m>>s>>a_>>b_;
    vector<long long> a(n),b(m);
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<m;++i)cin>>b[i];
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    long long suma=0,ans=0,act=0;
    int j=-1;
    for(int i=0;i<m;++i){
        if(suma+b_>s)break;
        suma+=b_;
        act+=b[i];
        j=i;
    }
    ans=act;
    for(int i=0;i<n;++i){
        suma+=a_;
        act+=a[i];
        while(suma>s && j>=0){
            suma-=b_;
            act-=b[j];
            j--;
        }
        if(suma>s)break;
        ans=max(ans, act);
    }
    cout<<ans<<"\n";
    return 0;
}
