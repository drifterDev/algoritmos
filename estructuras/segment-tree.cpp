// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
int nullValue = 0;
 
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
    return leftValue^rightValue;
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
  cin.tie(0);
  int n,q;cin>>n>>q;
  vi nums(n);
  for(int i=0;i<n;++i)cin>>nums[i];
  nodeST st(nums, 0, n-1);
  return 0;
}