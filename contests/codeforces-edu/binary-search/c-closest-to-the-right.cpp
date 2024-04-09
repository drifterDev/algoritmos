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
    for(int i=0;i<n;++i)cin>>nums[i];
    nums[n]=INT_MAX;
    while(q--){
        int x;
        cin>>x;
        int l=0,r=n;
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]>=x){
                r=m-1;
            }else{
                l=m+1;
            }
        }
        cout<<min(n, r+1)+1<<"\n";
    }
    return 0;
}
