// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;

struct matrix {
	int r,c;vector<vl> m;
	matrix(int r, int c, const vector<vl> &m):r(r),c(c),m(m){}

	matrix operator *(const matrix &b){
		matrix ans(this->r, b.c,vector<vl>(this->r,vl(b.c,LLONG_MAX)));
		for(int i=0;i<this->r;++i){
			for(int k=0;k<b.r;++k){
				if(m[i][k]==LLONG_MAX)continue;
				for (int j=0;j<b.c;++j){
					if(b.m[k][j]==LLONG_MAX)continue;
					ans.m[i][j]=min(ans.m[i][j], m[i][k]+b.m[k][j]);
				}
			}
		}
		return ans;
	}
};

matrix pow(matrix &b, ll p){
	matrix ans(b.r, b.c, vector<vl>(b.r, vl(b.c, LLONG_MAX)));
	for(int i=0;i<b.r;++i)ans.m[i][i]=0;
	while(p){
		if(p&1)ans=ans*b;
		b=b*b;
		p>>=1;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,m2;
	ll k;
	cin>>n>>m2>>k;
	vector<vl> matriz(n,vl(n,LLONG_MAX)); 
	ll c;
	for(int a,b,i=0;i<m2;++i){
		cin>>a>>b>>c;
		matriz[a-1][b-1]=min(c, matriz[a-1][b-1]);
	}
	matrix m(n,n,matriz);
	vector<vl> m3=pow(m,k).m;
	ll ans=LLONG_MAX;
	for(auto x:m3){
		for(auto y:x)ans=min(ans, y);
	}
	if(ans==LLONG_MAX)cout<<"IMPOSSIBLE\n";
	else cout<<ans<<"\n";
	return 0;
}