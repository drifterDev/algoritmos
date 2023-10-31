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

void suma(vl& nums, vector<vl>& dp,ll p,ll q,ll r, ll n){
    for(ll j=1;j<=n;j++){
        dp[j][1]=max(dp[j-1][1], nums[j-1]*p);
    }
    for(ll j=1;j<=n;j++){
        dp[j][2]=max(dp[j-1][2], dp[j][1]+nums[j-1]*q);
    }
    for(ll j=1;j<=n;j++){
        dp[j][3]=max(dp[j-1][3], dp[j][2]+nums[j-1]*r);
    }
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
ll p,q,r,n,act, res1=LLONG_MIN, res2=LLONG_MIN, res3=LLONG_MIN;
cin>>n>>p>>q>>r;
vl nums(n,0);
for(int i=0;i<n;i++)cin>>nums[i];
vector<vl> dp(n+1, vl(4, LLONG_MIN));
suma(nums, dp, p, q, r, n);
// for(ll i=0;i<n;i++){
//     cout<<dp[i+1][1]<<" "<<dp[i+1][2]<<" "<<dp[i+1][3]<<"\n";
// }
cout<<dp[n][3]<<"\n";
return 0;
}