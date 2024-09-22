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
				for(int j=0;j<b.c;++j){
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
	int n,p,k;cin>>n>>p>>k;
	vector<vl> matriz(n,vl(n,0));
	for(int i=0,a,b;i<p;++i){
		cin>>a>>b;
		matriz[a-1][b-1]=1;
	}
	matrix m(n,n,matriz);
	matriz=pow(m,k).m;
	ll ans=0;
	for(auto x:matriz){
		for(auto y:x)ans=mod(mod(ans,MOD)+mod(y,MOD),MOD);
	}
	cout<<ans<<"\n";
  	return 0;
}