#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
const int MOD = 1e9+7;

ll mod(ll a, ll m){
	return ((a%m)+m)%m;
}

// O(log(n))
struct matrix {
	int r,c;vector<vl> m;
	matrix(int r, int c, const vector<vl> &m):r(r),c(c),m(m){}

	matrix operator *(const matrix &b){
		matrix ans(this->r, b.c,vector<vl>(this->r,vl(b.c,0)));
		for(int i=0;i<this->r;++i){
			for(int k=0;k<b.r;++k){
				if(m[i][k]==0)continue;
				for (int j=0;j<b.c;++j){
					ans.m[i][j]+=mod(m[i][k], MOD)*mod(b.m[k][j], MOD);
					ans.m[i][j]=mod(ans.m[i][j], MOD);
				}
			}
		}
		return ans;
	}
};

matrix pow(matrix &b, ll p){
	matrix ans(b.r, b.c, vector<vl>(b.r, vl(b.c, 0)));
	for(int i=0;i<b.r;++i)ans.m[i][i]=1;
	while(p){
		if(p&1)ans=ans*b;
		b=b*b;
		p>>=1;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	// [1 1] [fib(p+1) fib(p)]
	// [1 0] [fib(p) fib(p-1)]
	vector<vl> matriz={{1, 1},{1, 0}};
	matrix m(2,2,matriz);
	ll n;cin>>n;
	cout<<pow(m,n).m[0][1]<<"\n";
	return 0;
}