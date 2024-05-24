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
	vector<ll> lazy1;
	vector<ll> lazy2;
    ll noVal=LLONG_MIN;
	ll null=0;

	ll oper(ll a, ll b){
        return a+b;
    }

    ll oper2(ll a,ll b, ll len){
        return a+(b*len);
    }

	void build(int n){
        size=1;
		while(size<n)size*=2;
		vals.assign(2*size, 0);
        lazy1.assign(2*size, noVal);
        lazy2.assign(2*size, 0);
	}

    void propagate(int x, int lx, int rx){
        if(rx-lx==1)return;
        int m=(lx+rx)/2;
        if(lazy1[x]!=noVal){
            lazy1[2*x+1]=lazy1[2*x+2]=lazy1[x];
            lazy2[2*x+1]=lazy2[2*x+2]=0;
            vals[2*x+1]=oper2(0,lazy1[x],m-lx);
            vals[2*x+2]=oper2(0,lazy1[x],rx-m);
        }
        if(lazy2[x]){
            vals[2*x+1]=oper2(vals[2*x+1],lazy2[x],m-lx);
            vals[2*x+2]=oper2(vals[2*x+2],lazy2[x],rx-m);
            lazy2[2*x+1]+=lazy2[x];
            lazy2[2*x+2]+=lazy2[x];
        }
        lazy1[x]=noVal;
        lazy2[x]=0;
    }

    void upd(int l, int r, ll v,int x, int lx, int rx, int op){
        propagate(x,lx,rx);
		if(lx>=r || l>=rx)return;
		if(lx>=l && rx<=r){
            if(op==1){
                lazy1[x]=v;
                lazy2[x]=0;
                vals[x]=oper2(0,v,rx-lx);
            }else{
                lazy2[x]+=v;
                vals[x]=oper2(vals[x],v,rx-lx);
            }
            return;
        }
		int m=(lx+rx)/2;
		upd(l,r,v,2*x+1,lx,m,op);
		upd(l,r,v,2*x+2,m,rx,op);
		vals[x]=oper(vals[2*x+1], vals[2*x+2]);
	}

	void upd(int l, int r, ll v,int op){
        upd(l,r+1,v,0,0,size, op);
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
            st.upd(l,r-1,v,1);
        }else if(op==2){
            cin>>l>>r>>v;
            st.upd(l,r-1,v,2);
        }else{
            cin>>i>>j;
            cout<<st.get(i,j-1)<<"\n";
        }
    }
    return 0;
}
