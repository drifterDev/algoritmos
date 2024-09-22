// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto &x:arr)cout<<x<<" ";cout<<"\n";
#define watch(x) cout<<#x<<"="<<x<<'\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
typedef long long ll;
typedef vector<ll> vl;
const int MOD = 1e9+7;

ll mod(ll a, ll m){return ((a%m)+m)%m;}

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

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	ll n;cin>>n;
	// ii dp={1,0};
	// for(int i=0;i<n;++i){
	//   int x=mod(mod(6*mod(dp.S,MOD),MOD)+mod(19*mod(dp.F,MOD),MOD),MOD);
	//   int y=mod(mod(20*mod(dp.S,MOD),MOD)+mod(7*mod(dp.F,MOD),MOD),MOD);
	//   dp={x,y};
	// }
	// cout<<dp.F<<"\n";
	// double p;cin>>n>>p;
	vector<vl> matriz={
		{19,6},
		{7,20}
	};
	matrix m(2,2,matriz);
	cout<<pow(m,n).m[0][0]<<"\n";
	return 0;
}