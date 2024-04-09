// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

long long suma(long long x){
    return (x*(x+1))/2;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    long long k,n;
    cin>>n>>k;
    vector<long long> nums(n);
    for(int i=0;i<n;++i)cin>>nums[i];
    long long act=0,j=-1,ans=0;
    for(long long i=0;i<n;++i){
        while(act+nums[i]>k){
            j++;
            act-=nums[j];
        }
        act+=nums[i];
        ans+=suma(i-j);
    }
    cout<<ans<<"\n";
    return 0;
}
