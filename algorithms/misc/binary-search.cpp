#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int x;

// O(log(n))
int binary_search(){
	int l=0,r=(int)a.size()-1;
	while(l<=r){
		int m=l+(r-l)/2;
		if(a[m]==x)return m;
		if(a[m]<x)l=m+1;
		else r=m-1;
	}return -1;
}

int main() {
	vector<int> v={1, 2, 4, 4, 5, 6, 7, 7, 8, 9};x=6;
	auto lower=lower_bound(v.begin(), v.end(),x);
	int idx=distance(v.begin(),lower);
	cout<<"Lower Bound de "<<x<<" en el índice: "<<idx<<"\n";
	cout<<"Lower Bound de "<<x<<": "<<*lower<<"\n";
	auto upper=upper_bound(v.begin(), v.end(),x);
	idx=distance(v.begin(),upper);
	cout<<"Upper Bound de "<<x<<" en el índice: "<<idx<<"\n";
	cout<<"Upper Bound de "<<x<<": "<<*upper<<"\n";
	return 0;
}