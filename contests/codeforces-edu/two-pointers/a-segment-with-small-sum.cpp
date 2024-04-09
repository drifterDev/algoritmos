// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n;
    long long k;
    cin>>n>>k;
    long long tmp,act=0;
    int j=-1,ans=0;
    vector<long long> nums(n);
    for(int i=0;i<n;++i)cin>>nums[i];
    for(int i=0;i<n;++i){
        if(act+nums[i]>k){
            while(act+nums[i]>k){
                j++;
                act-=nums[j];
            }
        }
        act+=nums[i];
        ans=max(ans, i-j);
    }
    cout<<ans<<"\n";
    return 0;
}
