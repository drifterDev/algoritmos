#include <bits/stdc++.h>
using namespace std;
#define sz(arr) (int)arr.size()

// O(n)
vector<int> z_function(string& s){
	int n=sz(s),l=0,r=0;
	vector<int> z(n);
	for(int i=1;i<n;i++){
		if(i<r)z[i]=min(r-i, z[i-l]);
		while(i+z[i]<n && s[z[i]]==s[i+z[i]])z[i]++;
		if(i+z[i]>r){
			l=i;
			r=i+z[i];
		}
	}
	return z;
}
