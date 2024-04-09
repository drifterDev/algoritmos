// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    long long p,n;
    cin>>n>>p;
    vector<long long> nums(2*n);
    long long suma=0;
    for(int i=0;i<n;++i){
        cin>>nums[i];
        nums[i+n]=nums[i];
        suma+=nums[i];
    }
    long long ans=p/suma * n;
    long long act=0,j=0,best=LONG_LONG_MAX,id=0;
    p%=suma;

    for(long long i=0;i<2*n;++i){
        act+=nums[i];
        while(act-nums[j]>=p && j<=i){
            act-=nums[j];
            j++;
        }
        if(act>=p && best>i-j+1){
            best=i-j+1;
            id=j%n;
        }
    }

    cout<<id+1<<" "<<ans+best<<"\n";
    return 0;
}
