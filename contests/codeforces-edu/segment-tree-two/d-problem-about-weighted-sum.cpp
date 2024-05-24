// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sumatoria(ll x,ll len){
    ll x2=x+len-1;
    ll tmp1=(x2*(x2+1))/2;
    ll tmp2=((x-1)*x)/2;
    return tmp1-tmp2;
}

struct Node{
    ll total,sum;
};

struct SegTree{
	int size;
	vector<Node> vals;
	vector<ll> lazy;
	Node null={0,0};

	Node oper(Node a, Node b){
        return {a.total+b.total, a.sum+b.sum};
    }

    Node oper2(Node a, ll b, ll len, ll i){
        return {
            a.total+b*sumatoria(i+1, len),
            a.sum+b*len
        };
    }

    void propagate(int x, int lx, int rx){
        if(rx-lx==1)return;
        if(lazy[x]==0)return;
        int m=(lx+rx)/2;
        lazy[2*x+1]+=lazy[x];
        vals[2*x+1]=oper2(vals[2*x+1],lazy[x],m-lx, lx);
        lazy[2*x+2]+=lazy[x]; 
        vals[2*x+2]=oper2(vals[2*x+2],lazy[x],rx-m, m);
        lazy[x]=0;
    }

	void build(vector<ll>& a, int x, int lx, int rx){
		if(rx-lx==1){
			if(lx<(int)a.size()){
				vals[x]={(lx+1)*a[lx],a[lx]};
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

    void upd(int l, int r, ll v,int x, int lx, int rx){
        propagate(x,lx,rx);
		if(lx>=r || l>=rx)return;
		if(lx>=l && rx<=r){
            lazy[x]=v;
			vals[x]=oper2(vals[x], v, rx-lx, lx);
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
		if(lx>=r || l>=rx)return 0;
		if(lx>=l && rx<=r){
            ll ans=vals[x].total-vals[x].sum*(1ll*l);
            return ans;
        }
		int m=(lx+rx)/2;
		ll v1=get(l,r,2*x+1,lx,m);
		ll v2=get(l,r,2*x+2,m,rx);
		return v1+v2;
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
    vector<ll> nums(n);
    for(int i=0;i<n;++i)cin>>nums[i];
    st.build(nums,n);
    int op,l,r,i,j;
    ll v;
    while(q--){
        cin>>op;
        if(op==1){
            cin>>l>>r>>v;
            st.upd(l-1,r-1,v);
        }else{
            cin>>i>>j;
            cout<<st.get(i-1,j-1)<<"\n";
        }
    }
    return 0;
}
