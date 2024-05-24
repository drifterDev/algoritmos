// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SegTree{
	int size;
	vector<ll> vals;
	vector<ll> lazy;
    ll noVal=LLONG_MIN;
	ll null=LLONG_MAX;

	ll oper(ll a, ll b){
        return min(a,b);
    }

    ll oper2(ll a, ll b){
        if(b==noVal)return a;
        return b;
    }

    void propagate(int x, int lx, int rx){
        if(rx-lx==1)return;
        if(lazy[x]==noVal)return;
        lazy[2*x+1]=oper2(lazy[2*x+1], lazy[x]);
        vals[2*x+1]=oper2(vals[2*x+1], lazy[x]);
        lazy[2*x+2]=oper2(lazy[2*x+2], lazy[x]);
        vals[2*x+2]=oper2(vals[2*x+2], lazy[x]); 
        lazy[x]=noVal;
    }

	void build(int n){
        size=1;
		while(size<n)size*=2;
		vals.assign(2*size, 0);
		lazy.assign(2*size, noVal);
	}

    void upd(int l, int r, ll v,int x, int lx, int rx){
        propagate(x,lx,rx);
		if(lx>=r || l>=rx)return;
		if(lx>=l && rx<=r){
            lazy[x]=oper2(lazy[x], v);
			vals[x]=oper2(vals[x], v);
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

	ll get(int l, int r, int x, int lx, int rx){
        propagate(x,lx,rx);
		if(lx>=r || l>=rx)return null;
		if(lx>=l && rx<=r)return vals[x];
		int m=(lx+rx)/2;
		ll v1=get(l,r,2*x+1,lx,m);
		ll v2=get(l,r,2*x+2,m,rx);
		return oper(v1,v2);
	}

	ll get(int l, int r){
		return get(l,r+1,0,0,size);
	}
};

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    SegTree st;
    st.build(n);
    int op,l,r,i,j;
    ll v;
    while(q--){
        cin>>op;
        if(op==1){
            cin>>l>>r>>v;
            st.upd(l,r-1,v);
        }else{
            cin>>i>>j;
            cout<<st.get(i,j-1)<<"\n";
        }
    }
    return 0;
}
