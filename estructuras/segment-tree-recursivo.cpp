#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node{ll seg,pref,suf,sum;};
struct SegTree{
	int size;
	vector<Node> vals;
	vector<ll> lazy;
    ll noVal=LLONG_MIN;
	Node null={0,0,0,0};

	Node oper(Node a, Node b){return null;}
    Node single(ll v){return null;}
    Node oper2(ll v, ll len){return null;}

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
        lazy.assign(2*size, 0);
		build(a, 0, 0, size);
	}

    void propagate(int x, int lx, int rx){
        if(rx-lx==1)return;
        if(lazy[x]==noVal)return;
        int m=(lx+rx)/2;
        lazy[2*x+1]=lazy[x];
        vals[2*x+1]=oper2(lazy[x], m-lx);
        lazy[2*x+2]=lazy[x]; 
        vals[2*x+2]=oper2(lazy[x], rx-m);
        lazy[x]=noVal;
    }

    void upd(int l, int r, ll v,int x, int lx, int rx){
        propagate(x,lx,rx);
		if(lx>=r || l>=rx)return;
		if(lx>=l && rx<=r){
            lazy[x]=v;
			vals[x]=oper2(v,rx-lx);
            return;
        }
		int m=(lx+rx)/2;
		upd(l,r,v,2*x+1,lx,m);
		upd(l,r,v,2*x+2,m,rx);
		vals[x]=oper(vals[2*x+1], vals[2*x+2]);
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


	Node get(int l, int r, int x, int lx, int rx){
        propagate(x,lx,rx);
		if(lx>=r || l>=rx)return null;
		if(lx>=l && rx<=r)return vals[x];
		int m=(lx+rx)/2;
		Node v1=get(l,r,2*x+1,lx,m);
		Node v2=get(l,r,2*x+2,m,rx);
		return oper(v1,v2);
	}

	void set(int i, ll val){set(i,val,0,0,size);}
	void upd(int l, int r, ll v){upd(l,r+1,v,0,0,size);}
	Node get(int l, int r){return get(l,r+1,0,0,size);}
};