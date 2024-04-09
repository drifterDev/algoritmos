// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n;
    long long r;
    cin>>n>>r;
    vector<long long> nums(n);
    for(int i=0;i<n;++i)cin>>nums[i];
    long long ans=0,j=0;
    for(long long i=0;i<n;++i){
        while(nums[i]-nums[j]>r){
            j++;
        }
        ans+=j;
    }
    
    cout<<ans<<"\n";
    return 0;
}
