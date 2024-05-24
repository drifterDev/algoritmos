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
	ll null=0;

	ll oper(ll a, ll b){
        return a+b;
    }

    ll oper2(ll a, ll b, ll len){
        return a+(b*len);
    }

	void build(int n){
        size=1;
		while(size<n)size*=2;
		vals.assign(2*size, 0);
		lazy.assign(2*size, 0);
	}

    void upd(int l, int r, ll v,int x, int lx, int rx){
		if(lx>=r || l>=rx)return;
		if(lx>=l && rx<=r){
            lazy[x]=oper(lazy[x], v);
			vals[x]=oper2(vals[x], v, rx-lx);
            return;
        }
		int m=(lx+rx)/2;
		upd(l,r,v,2*x+1,lx,m);
		upd(l,r,v,2*x+2,m,rx);
		vals[x]=oper2(oper(vals[2*x+1], vals[2*x+2]),lazy[x],rx-lx);
	}

	void upd(int l, int r, ll v){
        upd(l,r+1,v,0,0,size);
	}

	ll get(int l, int r, int x, int lx, int rx){
		if(lx>=r || l>=rx)return null;
		if(lx>=l && rx<=r)return vals[x];
		int m=(lx+rx)/2;
		ll v1=get(l,r,2*x+1,lx,m);
		ll v2=get(l,r,2*x+2,m,rx);
		return oper2(oper(v1,v2),lazy[x],min(r,rx)-max(l, lx));
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
