#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())

// O(n+k)
void counting_sort(vector<int>& a){ 
	int n=sz(a);
	int maxi=*max_element(all(a));
	int mini=*min_element(all(a));
	int k=maxi-mini+1;
	vector<int> cnt(k,0); 
	for(int i=0;i<n;++i)++cnt[a[i]-mini];
	for(int i=0,j=0;i<k;++i)
		while(cnt[i]--)a[j++]=i+mini;
}
