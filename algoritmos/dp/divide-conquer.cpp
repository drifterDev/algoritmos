#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
vl dp_before, dp_cur,g;
int m, n;

ll c(int i, int j){
	ll ans=0;
	// code...
	return ans;
}

// compute dp_cur[l], ... dp_cur[r] (inclusive)
void compute(int l, int r, int optl, int optr){
	if(l>r)return;
	int mid=(l+r)>>1;
	pair<ll, int> best={LLONG_MAX,-1};
	for(int k=optl;k<=min(mid, optr);++k){
		best=min(best, {(k?dp_before[k-1]:0) + c(k, mid), k});
	}
	dp_cur[mid]=best.first;
	int opt=best.second;
	compute(l, mid - 1, optl, opt);
	compute(mid + 1, r, opt, optr);
}

// O(m*n*log(n))
ll solve() {
	dp_before.assign(n,0);
	dp_cur.assign(n,0);
	for (int i=0;i<n;++i)dp_before[i]=c(0, i);
	for (int i=1;i<m;++i) {
		compute(0, n-1, 0, n-1);
		dp_before=dp_cur;
	}
	return dp_before[n - 1];
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	g.assign(n,0);
	for(int i=0;i<n;++i){
		cin>>g[i];
	}
	cout<<solve()<<"\n";
	return 0;
}