// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node{
    ll seg,pref,suf,sum;
};

struct SegTree{
	int size;
	vector<Node> vals;
	vector<ll> lazy;
    ll noVal=LLONG_MIN;
	Node null={0,0,0,0};

	Node oper(Node a, Node b){
        return {
            max({a.seg, b.seg, a.suf+b.pref}),
            max(a.pref, a.sum+b.pref),
            max(b.suf, b.sum+a.suf),
            a.sum+b.sum
        };
    }

    Node oper2(ll v, ll len){
        if(v<0)return {0,0,0,v*len};
        return {v*len,v*len,v*len,v*len};
    }

	void build(int x, int lx, int rx){
		if(rx-lx==1){
			vals[x]={0,0,0,0};
			return;
		}
		int m=(lx+rx)/2;
		build(2*x+1, lx, m);
		build(2*x+2, m, rx);
		vals[x]=oper(vals[2*x+1], vals[2*x+2]);
	}

	void build(int n){
        size=1;
		while(size<n)size*=2;
		vals.resize(2*size);
        lazy.assign(2*size, 0);
		build(0, 0, size);
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

	void upd(int l, int r, ll v){
        upd(l,r+1,v,0,0,size);
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

	Node get(int l, int r){
		return get(l,r+1,0,0,size);
	}
};

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    SegTree st;
    st.build(n);
    int l,r;
    ll v;
    while(q--){
        cin>>l>>r>>v;
        st.upd(l,r-1,v);
        cout<<st.get(0,n-1).seg<<"\n";
    }
    return 0;
}
