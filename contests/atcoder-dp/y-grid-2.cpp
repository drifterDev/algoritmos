// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD =1e9+7;
ll fact[1000001];

ll binpow(ll a, ll b, ll m){  
	ll res=1;a%=m;
	while(b>0){
		if(b&1)res=(res*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return res%m;
}

ll mod(ll a){return ((a%MOD)+MOD)%MOD;}
ll mult(ll a, ll b){return mod(mod(a)*mod(b));}
ll suma(ll a, ll b){return mod(mod(a)+mod(b));}
ll inv(ll a){return binpow(a,MOD-2, MOD);}

ll c(ll n, ll k){
    if(n<0 || k<0 || n<k)return 0;
    return mult(fact[n],inv(mult(fact[n-k], fact[k])));
}

ll ways(ll x1,ll y1, ll x2, ll y2){
    ll rows=x2-x1;
    ll cols=y2-y1;
    return c(rows+cols, max(rows, cols));
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    fact[0]=fact[1]=1;
    for(ll i=2;i<=1000000;++i){
        fact[i]=mult(fact[i-1],i);
    }
    ll h,w;
    int n;
    cin>>h>>w>>n;
    vector<pair<ll, ll>> obs(n+1);
    for(int i=0;i<n;++i){
        cin>>obs[i].first>>obs[i].second;
    }
    obs[n]={h,w};
    sort(obs.begin(), obs.end());

    // Buenos caminos hasta el obs i
    vector<ll> dp(n+1,0);
    dp[0]=ways(1,1,obs[0].first, obs[0].second);
    for(int i=1;i<n+1;++i){
        ll x=obs[i].first;
        ll y=obs[i].second;
        ll tmp=0;
        for(int j=0;j<i;++j){
            if(y<obs[j].second)continue;
            ll tmp2=ways(obs[j].first, obs[j].second, x, y);
            tmp=suma(tmp, mult(dp[j],tmp2));
        }
        dp[i]=(ways(1,1,x,y)+MOD-tmp)%MOD;
    }
    cout<<dp[n]<<"\n";
    return 0;
}
