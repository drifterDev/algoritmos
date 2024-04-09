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
    vector<long long> nums(n);
    for(int i=0;i<n;++i)cin>>nums[i];
    long long act=0;
    int j=-1,i=0,ans=INT_MAX;
    for(int i=0;i<n;++i){
        act+=nums[i];
        if(act<k)continue;
        while(act>=k){
            ans=min(ans, i-j);
            j++;
            act-=nums[j];
        }
    }
    cout<<(ans==INT_MAX?-1:ans)<<"\n";
    return 0;
}
