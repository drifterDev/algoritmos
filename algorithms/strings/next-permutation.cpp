#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) x.size())

// 1) encontrar el ultimo ai tal que ai<ai+1
// 2) encontrar el ultimo aj tal que ai<aj
// 3) invertir el segmento [i+1, n-1]
string nextPermutation(string& s){ // O(n)
	string ans(s);
	int n=sz(s);
	int j=n-2;
	while(j>=0 && ans[j]>=ans[j+1])j--;
	if(j<0)return "no permutation";
	int k=n-1;
	while(ans[j]>=ans[k])k--;
	swap(ans[j], ans[k]);
	int r=n-1,l=j+1;
	while(r>l)swap(ans[r--], ans[l++]);
	return ans;
}
