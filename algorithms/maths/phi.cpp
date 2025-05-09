#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())

// O(sqrt(n))
int phi(int n){
	if(n==1)return 0;
	int res=n;
	for(int i=2;1ll*i*i<=n;++i){
		if(n%i==0){
			while(n%i==0)n/=i;
			res-=res/i;
		}
	}
	if(n>1)res-=res/n;
	return res;
}

// O(n*log(log(n)))
vector<int> phin(int n){
	vector<int> phi(n+1);
	for(int i=0;i<=n;++i)phi[i]=i;
	for(int i=2;i<=n;++i)
		if(phi[i]==i)
			for(int j=i;j<=n;j+=i)
				phi[j]-=phi[j]/i;
	return phi;
}
