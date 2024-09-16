#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define all(x) x.begin(), x.end()
#define sz(arr) ((int) arr.size())

// O(log(n))
int binary_search(vi& nums, int target){
	int l=0,r=sz(nums)-1;
	while(l<=r){
		int m=l+(r-l)/2;
		if(nums[m]==target)return m;
		if(nums[m]<target)l=m+1;
		else r=m-1;
	}return -1;
}

int main() {
	vi v={1, 2, 4, 4, 5, 6, 7, 7,8, 9};
	int x=6;
	auto lower=lower_bound(all(v),x);
	auto upper=upper_bound(all(v),x);
	int indexLower=distance(v.begin(),lower);
	int indexUpper=distance(v.begin(),upper);
	cout<<"Lower Bound de "<<x<<" en el índice: "<<indexLower<<"\n";
	cout<<"Lower Bound de "<<x<<": "<<*lower<<"\n";
	cout<<"Upper Bound de "<<x<<" en el índice: "<<indexUpper<<"\n";
	cout<<"Upper Bound de "<<x<<": "<<*upper<<"\n";
	return 0;
}