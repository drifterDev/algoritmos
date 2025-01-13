#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) x.size())

// 1) encontrar el ultimo ai tal que ai<ai+1
// 2) encontrar el ultimo aj tal que ai<aj
// 3) invertir el segmento [i+1, n-1]
string nextPermutation(string& str){ // O(n)
	string result(str);
	int n=str.length();
	int j=n-2;
	while(j>=0 && result[j]>=result[j+1])j--;
	if(j<0)return "no permutation";
	int k=n-1;
	while(result[j]>=result[k])k--;
	swap(result[j], result[k]);
	int r=n-1;
	int l=j+1;
	while(r>l)swap(result[r--], result[l++]);
	return result;
}
