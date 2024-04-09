// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;++i)cin>>nums[i];
    map<int, int> mp;
    int act=0;
    long long ans=0,j=-1;
    for(long long i=0;i<n;++i){
        mp[nums[i]]++;
        while(mp.size()>k){
            j++;
            mp[nums[j]]--;
            if(mp[nums[j]]==0)mp.erase(nums[j]);
        }
        ans+=i-j;
    }
    cout<<ans<<"\n";
    return 0;
}
