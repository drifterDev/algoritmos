#include <bits/stdc++.h>
using namespace std;

int conv(char ch){return ((ch>='a' && ch<='z')?ch-'a':ch-'A'+26);}
vector<string> split(string& s, char c=' '){
	vector<string> res;
	stringstream ss(s);
	string sub;
	while(getline(ss, sub, c))res.push_back(sub);
	return res;
}

// for(char& c:s)c=toupper(c);
// for(char& c:s)c=tolower(c);
// int n=stoi(s); De string a entero
// int n=stoi(s, nullptr, 2); base 2
// double d=stod(s); De string a double
// string s=to_string(n); De entero a string