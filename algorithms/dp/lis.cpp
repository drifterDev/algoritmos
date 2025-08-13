// O(n*log(n))
// change the type and check equal
typedef int T;
vi lis(vector<T>& a, bool equal){
	vi prev(sz(a));
	typedef pair<T, int> p;
	vector<p> res;
	for(int i=0;i<sz(a);++i){
		auto it=lower_bound(all(res), p{a[i],(equal?i:0)});
		if(it==res.end())res.emplace_back(),it=res.end()-1;
		*it={a[i],i};
		prev[i]=(it==res.begin())?0:(it-1)->second;
	}
	int l=sz(res),act=res.back().second;
	vi ans(l);
	while(l--)ans[l]=act,act=prev[act];
	return ans;
}
