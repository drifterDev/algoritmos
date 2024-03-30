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

ll dp(vector<vi>& happy, int n){
    vector<vi> res(n,vi(3,0));
    for(int i=0;i<3;i++)res[0][i]=happy[0][i];
    for(int i=1;i<n;i++){
        res[i][0]=happy[i][0]+max(res[i-1][1], res[i-1][2]);
        res[i][1]=happy[i][1]+max(res[i-1][0], res[i-1][2]);
        res[i][2]=happy[i][2]+max(res[i-1][0], res[i-1][1]);
    }
    // for(int i=0;i<n;i++)cout<<res[i][0]<<" "<<res[i][1]<<" "<<res[i][2]<<"\n";
    return max(res[n-1][0], max(res[n-1][1], res[n-1][2]));
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n;cin>>n;
vector<vi> happy(n,vi(3,0));
for(int i=0;i<n;i++)cin>>happy[i][0]>>happy[i][1]>>happy[i][2];
ll res=dp(happy, n);
cout<<res<<"\n";
return 0;
}