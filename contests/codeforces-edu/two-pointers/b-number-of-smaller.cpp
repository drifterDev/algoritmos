// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,m;cin>>n>>m;
    vector<int> a(n+1),b(m);
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<m;++i)cin>>b[i];
    vector<int> ans(m);
    a[n]=INT_MAX;
    int j=0;
    for(int i=0;i<m;++i){
        while(a[j]<b[i])j++;
        ans[i]=j;
    }
    for(auto x:ans)cout<<x<<" ";
    cout<<"\n";
    return 0;
}
