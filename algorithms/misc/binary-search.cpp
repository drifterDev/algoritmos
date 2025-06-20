#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int x;

// O(log(n))
bool check(int x);
void binary_search(){
	int l=0,r=(int)a.size()-1;
	while(l<=r){
		int m=l+(r-l)/2;
		if(check(m))l=m+1;
		else r=m-1;
	}
}

void santa_binaria(){
	int l=-1; // the last 0
	int r=a.size(); // the first 1
	while(r-l>1){
		int m=l+(r-l)/2;
		if(check(m))l=m;
		else r=m;
	}
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