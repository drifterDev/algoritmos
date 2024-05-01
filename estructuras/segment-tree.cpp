// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

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

typedef long long T;
struct SegTree{
	int n;vector<T> v;
	T null=0;
	T op(T a, T b){return a^b;}
	SegTree(int n):n(n),v(2*n,null){}
	SegTree(vector<T>& a):n(sz(a)),v(2*n){
		for(int i=0;i<n;i++)v[n+i]=a[i];
		for(int i=n-1;i>=1;--i)v[i]=op(v[i<<1],v[i<<1|1]);
	}

	void upd(int k, T nv){
		for(v[k+=n]=nv;k>1;k>>= 1)v[k>>1]=op(v[k], v[k^1]);
	}

	T get(int l, int r){
		T vl=null,vr=null;
		for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
			if(l&1)vl=op(vl,v[l++]);
			if(r&1)vr=op(v[--r],vr);
		}
		return op(vl, vr);
	}
};


struct Node{
    ll seg,pref,suf,sum;
};

struct SegTree{
	int size;
	vector<Node> vals;
	Node null;

	Node oper(Node a, Node b){
        return {
            max({a.seg, b.seg, a.suf+b.pref}),
            max(a.pref, a.sum+b.pref),
            max(b.suf, b.sum+a.suf),
            a.sum+b.sum
        };
    }

    Node single(ll v){
        if(v<0)return {0,0,0,v};
        return {v,v,v,v};
    }

	void build(vector<ll>& a, int x, int lx, int rx){
		if(rx-lx==1){
			if(lx<(int)a.size()){
				vals[x]=single(a[lx]);
			}
			return;
		}
		int m=(lx+rx)/2;
		build(a, 2*x+1, lx, m);
		build(a, 2*x+2, m, rx);
		vals[x]=oper(vals[2*x+1], vals[2*x+2]);
	}

	void build(vector<ll>& a,int n){
        size=1;
		while(size<n)size*=2;
		vals.resize(2*size);
		build(a, 0, 0, size);
	}

	void set(int i, ll val, int x, int lx, int rx){
		if(rx-lx==1){
			vals[x]=single(val);
			return;
		}
		int m=(lx+rx)/2;
		if(i<m){
			set(i,val,2*x+1,lx,m);
		}else{
			set(i,val,2*x+2,m,rx);
		}
		vals[x]=oper(vals[2*x+1], vals[2*x+2]);
	}

	void set(int i, ll val){
		set(i,val,0,0,size);
	}

	Node get(int l, int r, int x, int lx, int rx){
		if(lx>=r || l>=rx)return null;
		if(lx>=l && rx<=r)return vals[x];
		int m=(lx+rx)/2;
		Node v1=get(l,r,2*x+1,lx,m);
		Node v2=get(l,r,2*x+2,m,rx);
		return oper(v1,v2);
	}

	Node get(int l, int r){
		return get(l,r+1,0,0,size);
	}
};