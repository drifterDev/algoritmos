#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// O(log(b))
ll binpow(ll a, ll b, ll m){  
	ll res=1;a%=m;
	while(b>0){
		if(b&1)res=(res*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return res%m;
}