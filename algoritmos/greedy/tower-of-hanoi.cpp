#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
map<ii, int> mp;
vii ans;

void hanoi(int x, int start, int end){
	if(x<=0)return;
	hanoi(x-1, start, mp[{start, end}]);
	ans.push_back({start, end});
	hanoi(x-1, mp[{start, end}], end);
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cout<<setprecision(20)<<fixed;
	mp[{1,3}]=mp[{3,1}]=2;
	mp[{1,2}]=mp[{2,1}]=3;
	mp[{2,3}]=mp[{3,2}]=1;
	int n;cin>>n;
	hanoi(n,1,3);
	cout<<ans.size()<<"\n";
	for(auto x:ans){
		cout<<x.first<<" "<<x.second<<"\n";
	}
	return 0;
}
