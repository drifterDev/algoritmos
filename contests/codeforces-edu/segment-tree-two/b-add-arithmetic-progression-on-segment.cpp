// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SegTree{
	int size;
	vector<ll> lazy1;
	vector<ll> lazy2;

	void build(int n){
        size=1;
		while(size<n)size*=2;
		lazy1.assign(2*size, 0);
		lazy2.assign(2*size, 0);
	}

    void upd(int l, int r,int x, int lx, int rx,ll a,ll d){
		if(lx>=r || l>=rx)return;
		if(lx>=l && rx<=r){
            lazy1[x]+=(lx-l)*d+a;
            lazy2[x]+=d;
            return;
        }
		int m=(lx+rx)/2;
		upd(l,r,2*x+1,lx,m,a,d);
		upd(l,r,2*x+2,m,rx,a,d);
	}

	void upd(int l, int r, ll a, ll d){
        upd(l,r+1,0,0,size,a,d);
	}

	ll get(int i, int x, int lx, int rx){
		if(rx-lx==1){
			return lazy1[x];
		}
		int m=(lx+rx)/2;
        ll ans=0;
		if(i<m){
			ans=get(i,2*x+1,lx,m);
		}else{
			ans=get(i,2*x+2,m,rx);
		}
		return ans+lazy1[x]+lazy2[x]*(i-lx);
	}

	ll get(int i){
		return get(i,0,0,size);
	}
};

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    SegTree st;
    st.build(n);
    int op,l,r,i,j;
    ll a,d;
    while(q--){
        cin>>op;
        if(op==1){
            cin>>l>>r>>a>>d;
            st.upd(l-1,r-1,a,d);
        }else{
            cin>>i;
            cout<<st.get(i-1)<<"\n";
        }
    }
    return 0;
}
