#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod(int a, int m);
int mul(int a, int b, int m);

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

int binpow(int a, int b, int m){  
	int res=1;a=mod(a,m);
	while(b>0){
		if(b&1)res=mul(res,a,m);
		a=mul(a,a,m);
		b>>=1;
	}
	return mod(res,m);
}
