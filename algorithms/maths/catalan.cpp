#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7, n=1e6;
ll cat[n+1];

ll inv(ll x, ll m);
ll mult(ll a, ll b);

// O(n*log(mod))
void build(){
	cat[0]=1;
	for(int i=1;i<=n;++i){
		cat[i]=mult(mult(4,i)-2+MOD, cat[i-1]);
		cat[i]=mult(cat[i], inv(i+1, MOD));
	}
}
