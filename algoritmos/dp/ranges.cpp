// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    string s;cin>>s;
    int n=s.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1,0));
    
    for(int j=0;j<=n;++j){
        for(int i=0;i<n-j;++i){
            dp[i][i+j]=dp[i+1][i+j]+1;
            for(int k=i+1;k<=i+j;++k){
                if(s[i]!=s[k])continue;
                dp[i][i+j]=min(dp[i][i+j], dp[i+1][k-1]+dp[k+1][i+j]);
            }
        }
    }

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cout<<dp[i][j]<<" ";
        }cout<<"\n";
    }
    return 0;
}
