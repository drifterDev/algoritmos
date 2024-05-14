// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
ll dp[10002][102][2];
string n;
ll d;

ll mod(ll a, ll m){return ((a%m)+m)%m;}
ll suma(ll a, ll b, ll m){return mod(mod(a,m)+mod(b,m),m);}

ll dfs(ll x=0,ll y=0,bool z=0){
	if(dp[x][y][z]!=-1){
        return dp[x][y][z];
    }
	dp[x][y][z]=(y%d==0);
	if(x==(int)n.length()){
		return dp[x][y][z];
	}
	ll limit=9;
	if(!z){
		limit=n[x]-'0';
	}
	ll tmp=0;
	for(ll i=0;i<=limit;++i){
		tmp=suma(tmp, dfs(x+1, suma(y,i,d), (z || i<limit)), MOD);
	}
	return dp[x][y][z]=tmp;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>d;
    memset(dp, -1, sizeof(dp));
	cout<<mod(dfs()-1ll,MOD)<<"\n";
	return 0;
}
