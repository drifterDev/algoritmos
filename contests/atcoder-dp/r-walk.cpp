// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
const int MOD = 1e9+7;

ll mod(ll a, ll m){
  return ((a%m)+m)%m;
}

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

ll suma(ll x,ll y){
  return mod(mod(x,MOD)+mod(y,MOD),MOD);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;cin>>n;
  ll k;cin>>k;
  vector<vl> matriz(n,vl(n));
  for(int i=0;i<n;++i){
    for(int j=0;j<n;++j)cin>>matriz[i][j];
  }
  matrix m(n,n,matriz);
  vector<vl> mat=pow(m, k).m;
  ll ans=0;
  for(auto x:mat){
    for(auto y:x)ans=suma(ans, y);
  }
  cout<<ans<<"\n";
  return 0;
}