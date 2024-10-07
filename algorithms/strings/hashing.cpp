#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
// 1000234999, 1000567999, 1000111997, 1000777121, 1001265673, 1001864327, 999727999, 1070777777
const int mod[2] = { 1001864327, 1001265673 }; 
const ii base(257, 367), zero(0, 0), one(1, 1);
const int maxn = 1e6;

inline int add(int a, int b, int m){return a+b>=m?a+b-m:a+b;}
inline int sbt(int a, int b, int m){return a-b<0?a-b+m:a-b;}
inline int mul(int a, int b, int m){return ll(a)*b%m;} 
inline ll operator ! (const ii a){return (ll(a.first)<<32)|a.second;}
inline ii operator + (const ii& a, const ii& b){return {add(a.first, b.first, mod[0]), add(a.second, b.second, mod[1])};}
inline ii operator - (const ii& a, const ii& b){return {sbt(a.first, b.first, mod[0]), sbt(a.second, b.second, mod[1])};}
inline ii operator * (const ii& a, const ii& b){return {mul(a.first, b.first, mod[0]), mul(a.second, b.second, mod[1])};}

ii p[maxn+1];
void prepare(){	// Acordate del prepare()!!
	p[0]=one;
	for(int i=1;i<=maxn;i++)p[i]=p[i-1]*base;
}

template <class type> 
struct hashing{
	vector<ii> h;
	hashing(type& t){
		h.resize((int)t.size()+1);
		h[0]=zero;
		for(int i=1;i<(int)h.size();++i)
			h[i]=h[i-1]*base + ii{t[i-1], t[i-1]};
	}

	ii get(int l, int r){
		return h[r+1]-h[l]*p[r-l+1];
	}
};

ii combine(ii a, ii b, int lenb){
	return a*p[lenb]+b;
}
