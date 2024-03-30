// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout<<#x<<"="<<x<<'\n'
#define trace(x) cerr<<#x<<"="<<x<<'\n'
#define sz(arr) ((int) arr.size())
#define len(str) ((int) str.length())
#define all(x) x.begin(), x.end()
#define F first
#define S second
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
ll nullValue = -INFL;
 
struct nodeST{
nodeST *left,*right;
ll l,r;ll value,lazy;
nodeST(vl &v,ll l,ll r):l(l),r(r){
  ll m=(l+r)>>1;
  lazy=0;
  if(l!=r){
    left=new nodeST(v, l, m);
    right=new nodeST(v, m+1, r);
    value=opt(left->value, right->value);
  }
  else value = v[l];
}
 
ll opt(ll leftValue, ll rightValue){
  return max(leftValue,rightValue);
}
 
void propagate(){
  if (lazy){
    value+=lazy;
    if(l!=r)left->lazy+=lazy,right->lazy+=lazy;
    lazy=0;
  }
}
 
ll get(ll i, ll j){
  propagate();
  if(l>=i && r<=j)return value;
  if(l>j || r<i)return nullValue;
  return opt(left->get(i,j),right->get(i,j));
}
 
void upd(ll i, ll j, ll nv){
  propagate();
  if (l>j  || r<i)return;
  if (l>=i && r<=j){
    lazy+=nv;
    propagate();
    // value = nv;
    return;
  }
  left->upd(i,j,nv);
  right->upd(i,j,nv);
  value=opt(left->value,right->value);
}
 
void upd(ll k, ll nv){
  if(l>k  || r<k)return;
  if(l>=k && r<=k){
    value=nv;
    return;
  }
  left->upd(k, nv);
  right->upd(k, nv);
  value=opt(left->value, right->value);
}
};
 
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
ll n,q;cin>>n>>q;
vl nums(n);
cin>>nums[0];
for(int i=1;i<n;++i){
  cin>>nums[i];
  nums[i]+=nums[i-1];
}
nodeST st(nums, 0, n-1);
ll tmp,a,b,c,op;
while(q--){
  cin>>c>>a>>b;
  if(c==1){
    op=(a!=1?st.get(a-2,a-2):0);
    tmp=st.get(a-1,a-1)-op;
    st.upd(a-1,n-1,-tmp+b);
  }else{
    op=(a!=1?st.get(a-2,a-2):0);
    cout<<max(st.get(a-1,b-1)-op,(ll)0)<<"\n";
  }
}
return 0;
}
