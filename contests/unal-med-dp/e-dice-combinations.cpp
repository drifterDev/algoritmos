// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef long long ll;
const int MOD = 1e9+7;
int dice[10000000];
 
 
ll dp(ll n){
    if(n==1)return dice[n-1];
    else if(n==2)return dice[n-1];
    else{
        if(dice[n-1]!=0)return dice[n-1];
        ll res=0;
        for(int i=1;i<7;i++){
            if(n-i==0)res++;
            else if(n-i>0)res+=(1*(dp(n-i)%MOD))%MOD;
            else break;
            res%=MOD;
        }
        dice[n-1]=res;
        return res%MOD;
    }
}
 
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
ll n;cin>>n;
dice[0]=1;dice[1]=2;
cout<<dp(n)<<"\n";
return 0;
}
