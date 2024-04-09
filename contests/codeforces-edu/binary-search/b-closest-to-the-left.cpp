// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    vector<int> nums(n+1);
    for(int i=1;i<=n;++i)cin>>nums[i];
    nums[0]=INT_MIN;
    while(q--){
        int x;
        cin>>x;
        int l=0,r=n;
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]<=x){
                l=m+1;
            }else{
                r=m-1;
            }
        }
        cout<<max(0, l-1)<<"\n";
    }
    return 0;
}
