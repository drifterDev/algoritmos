#include <bits/stdc++.h>
using namespace std;

int conv(char ch){return ((ch>='a' && ch<='z')?ch-'a':ch-'A'+26);}
// if the char changes, uncomment it and use the second parameter
vector<string> split(const string &s/*, char c */){
	vector<string> v;
	stringstream ss(s);
	string sub;
	while(ss>>sub)v.push_back(sub);
	// while(getline(ss,sub,c))if(sz(sub))v.push_back(sub);
	return v;
}

void test(){
	string s;
	for(char& c:s)c=toupper(c); 
	for(char& c:s)c=tolower(c); 
	int n=stoi(s); // string to number
	int n=stoi(s, nullptr, 2); // bin string to number 
	double d=stod(s); // string to double
	string s=to_string(n); // number to string
	cout<<"\U0001F600"; // emojis
}