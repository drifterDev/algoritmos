#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

// O(nlogn)
int lis(vector<int>& a){
	int n=(int)a.size(),last=0;
	vector<int> dp(n+1,INT_MAX),cnt(n,0);
	dp[0]=INT_MIN;

	for(int i=0;i<n;++i){
		int j=lower_bound(all(dp), a[i])-dp.begin(); // upper_bound if <=
		if(dp[j-1]<a[i] && a[i]<dp[j]){ // dp[j-1]<=a[i] if <=
			dp[j]=a[i];
			last=max(last,j);
		}
		cnt[i]=j;
	}

	int ans=0;
	for(int i=0;i<=n;i++){
		if(dp[i]<INT_MAX)ans=i;
	}

	vector<int> LIS(ans);
	int act=ans;
	for(int i=n-1;i>=0;--i){
		if(cnt[i]==act){
			LIS[act-1]=a[i];
			act--;
		}
	}

	return ans;
}
