// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;++i)cin>>nums[i];
    sort(nums.begin(), nums.end());
    int q;
    cin>>q;
    while(q--){
        int x1,x2;
        cin>>x1>>x2;
        int l=0,r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]<x1){
                l=m+1;
            }else{
                r=m-1;
            }
        }
        int tmp=max(0, l-1);
        if(nums[tmp]<x1)tmp++;
        l=0,r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]>x2){
                r=m-1;
            }else{
                l=m+1;
            }
        }
        int tmp2=min(n-1, r+1);
        if(nums[tmp2]>x2)tmp2--;
        cout<<tmp2-tmp+1<<" ";
    }
    cout<<"\n";
    return 0;
}
