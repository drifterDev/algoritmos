// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef long long ll;
const int INF = 1e9;
int dp[501][501];
 
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
int a,b;cin>>a>>b;
for(int i=1;i<=500;i++){
    for(int j=1;j<=500;j++){
        if(i==j)dp[i][j]=0;
        else dp[i][j]=INF;
    }
}
for(int i=1;i<=a;i++){
    for(int j=1;j<=b;j++){
        for(int k=1;k<i;k++)dp[i][j]=min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
        for(int k=1;k<j;k++)dp[i][j]=min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
    }
}
cout<<dp[a][b]<<"\n";
return 0;
}
