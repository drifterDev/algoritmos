#include <bits/stdc++.h>
using namespace std;

// O(n)
vector<int> phi(string& s){
	int n=(int)s.size();
	vector<int> tmp(n);
	for(int i=1,j=0;i<n;++i){
		while(j>0 && s[j]!=s[i])j=tmp[j-1];
		if(s[i]==s[j])j++;
		tmp[i]=j;
	}
	return tmp;
}

// O(n+m)
int kmp(string& s, string& p){
	int n=(int)s.size(),m=(int)p.size(),cnt=0;
	vector<int> pi=phi(p);
	for(int i=0,j=0;i<n;++i){
		while(j && s[i]!=p[j])j=pi[j-1];
		if(s[i]==p[j])j++;
		if(j==m){
			cnt++;
			j=pi[j-1];
		}
	}
	return cnt;
}