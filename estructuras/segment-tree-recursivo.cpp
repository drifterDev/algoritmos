#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) x.size())
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;
int nullValue = 0;
 
struct NodeST{
	NodeST *left,*right;
	int l,r;ll value,lazy;
	NodeST(vi &v,int l,int r):l(l),r(r){
		int m=(l+r)>>1;
		lazy=0;
		if(l!=r){
			left=new NodeST(v, l, m);
			right=new NodeST(v, m+1, r);
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
