const int MOD = 1e9+7, n=1e6;
ll cat[n+1];

ll inv(ll x, ll m);
ll mul(ll a, ll b);

// O(n*log(mod))
void build(){
	cat[0]=1;
	for(int i=1;i<=n;++i){
		cat[i]=mul(mul(4,i)-2+MOD, cat[i-1]);
		cat[i]=mul(cat[i], inv(i+1, MOD));
	}
}
