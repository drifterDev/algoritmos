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
int nullValue = INF;
 
struct nodeST{
nodeST *left,*right;
int l,r;ll value,lazy;
nodeST(vi &v,int l,int r):l(l),r(r){
  int m=(l+r)>>1;
  lazy=0;
  if(l!=r){
    left=new nodeST(v, l, m);
    right=new nodeST(v, m+1, r);
    value=opt(left->value, right->value);
  }
  else value = v[l];
}
 
ll opt(ll leftValue, ll rightValue){
  return min(leftValue,rightValue);
}
 
void propagate(){
  if (lazy){
    value+=lazy*(r-l+1);
    if(l!=r)left->lazy+=lazy,right->lazy+=lazy;
    lazy=0;
  }
}
 
ll get(int i, int j){
  propagate();
  if(l>=i && r<=j)return value;
  if(l>j || r<i)return nullValue;
  return opt(left->get(i,j),right->get(i,j));
}
 
void upd(int i, int j, int nv){
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
 
void upd(int k, int nv){
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
int n,q;cin>>n>>q;
vi nums1(n),nums2(n);
for(int i=0,tmp;i<n;i++){
  cin>>tmp;
  nums1[i]=tmp+i+1;
  nums2[i]=tmp-(i+1);
}
nodeST minUp(nums1, 0, n-1), minDown(nums2,0,n-1);
int x,a,b;
while(q--){
  cin>>x>>a;
  if(x==2){
    cout<<min(minDown.get(0,a-1)+a, minUp.get(a-1,n-1)-a)<<"\n";
  }else{
    cin>>b;
    minUp.upd(a-1, b+a);
    minDown.upd(a-1, b-a);
  }
}
return 0;
}
