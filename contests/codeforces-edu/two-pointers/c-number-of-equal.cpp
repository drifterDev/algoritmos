// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,m;cin>>n>>m;
    map<int, long long> mp;
    vector<int> a(n),b(m);
    for(int i=0;i<n;++i){
        cin>>a[i];
        mp[a[i]]++;
    }
    long long ans=0;
    for(int i=0;i<m;++i){
        cin>>b[i];
        ans+=mp[b[i]];
    }
    cout<<ans<<"\n";
    return 0;
}
