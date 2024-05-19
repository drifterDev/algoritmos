// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
double dp[301][301][301];
int n;

double media(int x, int y ,int z){
    if(x<0 || y<0 || z<0)return 0;
    if(x==0 && y==0 && z==0)return 0;
    if(dp[x][y][z]>=0)return dp[x][y][z];
    double ans=n;
    ans+=x*media(x-1,y,z);
    ans+=y*media(x+1,y-1,z);
    ans+=z*media(x,y+1,z-1);
    return dp[x][y][z]=ans/(x+y+z);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout<<setprecision(10)<<fixed;
    memset(dp, -1, sizeof(dp));
    cin>>n;
    int n1=0,n2=0,n3=0;
    for(int a,i=0;i<n;++i){
        cin>>a;
        n1+=(a==1);
        n2+=(a==2);
        n3+=(a==3);
    }
    cout<<media(n1,n2,n3)<<"\n";
    return 0;
}
