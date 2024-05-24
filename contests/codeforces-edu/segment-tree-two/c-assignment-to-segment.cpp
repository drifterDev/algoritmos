// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SegTree{
	int size;
    ll noVal=LLONG_MIN;
	vector<ll> vals;

    ll oper(ll a, ll b){
        if(b==noVal)return a;
        return b;
    }
    
	void build(int n){
        size=1;
		while(size<n)size*=2;
		vals.assign(2*size, 0);
	}

    void propagate(int x, int lx, int rx){
        if(rx-lx==1)return;
        vals[2*x+1]=oper(vals[2*x+1], vals[x]);
        vals[2*x+2]=oper(vals[2*x+2], vals[x]);
        vals[x]=noVal;
    }

	ll get(int i, int x, int lx, int rx){
        propagate(x,lx,rx);
		if(rx-lx==1){
			return vals[x];
		}
		int m=(lx+rx)/2;
        ll ans=0;
		if(i<m){
			ans=get(i,2*x+1,lx,m);
		}else{
			ans=get(i,2*x+2,m,rx);
		}
        return ans;
	}

	ll get(int i){
		return get(i,0,0,size);
	}

	void upd(int l, int r,ll v, int x, int lx, int rx){
        propagate(x,lx,rx);
		if(lx>=r || l>=rx)return;
		if(lx>=l && rx<=r){
            vals[x]=oper(vals[x],v);
            return;
        }
		int m=(lx+rx)/2;
		upd(l,r,v,2*x+1,lx,m);
		upd(l,r,v,2*x+2,m,rx);
		return;
	}

	void upd(int l, int r, ll v){
		upd(l,r+1,v,0,0,size);
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
            cin>>i;
            cout<<st.get(i)<<"\n";
        }
    }
    return 0;
}
