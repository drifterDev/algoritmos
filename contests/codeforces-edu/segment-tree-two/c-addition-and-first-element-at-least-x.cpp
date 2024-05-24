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

	ll oper(ll a, ll b){
        return max(a,b);
    }

    void propagate(int x,int lx, int rx){
        if(rx-lx==1)return;
        lazy[2*x+1]+=lazy[x];
        vals[2*x+1]+=lazy[x];
        lazy[2*x+2]+=lazy[x];
        vals[2*x+2]+=lazy[x];
        lazy[x]=0;
    }

	void build(int n){
        size=1;
		while(size<n)size*=2;
		vals.assign(2*size, 0);
		lazy.assign(2*size, 0);
	}

    void upd(int l, int r, ll v,int x, int lx, int rx){
        propagate(x,lx,rx);
		if(lx>=r || l>=rx)return;
		if(lx>=l && rx<=r){
            lazy[x]+=v;
			vals[x]+=v;
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

	int get(int l,ll v, int x, int lx, int rx){
        propagate(x,lx,rx);
		if(vals[x]<v)return -1;
        if(rx-lx==1){
            if(vals[x]>=v)return lx;
            return -1;
        }
		int m=(lx+rx)/2;
        if(m>l){
            int v1=get(l,v,2*x+1,lx,m);
            if(v1!=-1)return v1;
        }
        return get(l,v,2*x+2,m,rx);
	}

	int get(int l, ll v){
		return get(l,v,0,0,size);
	}
};

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    SegTree st;
    st.build(n);
    int op,l,r,i;
    ll v;
    while(q--){
        cin>>op;
        if(op==1){
            cin>>l>>r>>v;
            st.upd(l,r-1,v);
        }else{
            cin>>v>>i;
            cout<<st.get(i,v)<<"\n";
        }
    }
    return 0;
}
