// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

void dp(vector<vi>& mapa, int n, int m){
    mapa[n-1][m-1]=1;
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(i==n-1 && j==m-1)continue;
            else if(mapa[i][j]==-1)continue;
            else if(i==n-1){
                if(mapa[i][j+1]!=-1)mapa[i][j]=(mapa[i][j+1]%MOD);
                else continue;
            }else if(j==m-1){
                if(mapa[i+1][j]!=-1)mapa[i][j]=(mapa[i+1][j]%MOD);
                else continue;
            }else{
                if(mapa[i+1][j]==-1 && mapa[i][j+1]==-1)continue;
                else if(mapa[i+1][j]==-1)mapa[i][j]=(mapa[i][j+1]%MOD);
                else if(mapa[i][j+1]==-1)mapa[i][j]=(mapa[i+1][j]%MOD);
                else mapa[i][j]=((mapa[i][j+1]%MOD)+(mapa[i+1][j]%MOD))%MOD;
            }
        }
    }
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
int n,m;cin>>n>>m;
vector<vi> mapa(n,vi(m,0));
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        char act;cin>>act;
        if(act=='.')mapa[i][j]=0;
        else mapa[i][j]=-1;
    }
}
dp(mapa, n, m);
cout<<mapa[0][0]<<"\n";
// for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){
//         cout<<mapa[i][j]<<" ";
//     }cout<<"\n";
// }
return 0;
}