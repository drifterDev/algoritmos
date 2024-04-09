// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,m;cin>>n>>m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<m;++i)cin>>b[i];
    vector<int> ans(n+m);
    int i=0,j=0,k=0;
    while(k<n+m){
        if(i<n && j<m){
            if(a[i]<=b[j]){
                ans[k]=a[i];
                i++;k++;
            }else{
                ans[k]=b[j];
                j++;k++;
            }
        }else if(i<n){
            ans[k]=a[i];
            i++;k++;
        }else if(j<m){
            ans[k]=b[j];
            j++;k++;
        }
    }
    for(auto x:ans)cout<<x<<" ";
    cout<<"\n";
    return 0;
}
