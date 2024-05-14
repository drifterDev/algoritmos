// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; 

struct SegTree{
	int size;
	vector<ll> vals;
	ll null=LONG_LONG_MIN;

	ll oper(ll a, ll b){
        return max(a,b);
    }

	void build(vector<ll>& a, int x, int lx, int rx){
		if(rx-lx==1){
			if(lx<(int)a.size()){
				vals[x]=a[lx];
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
			vals[x]=val;
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

	ll get(int l, int r, int x, int lx, int rx){
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
    int n;cin>>n;
    ordered_set s;
    vector<int> h(n);
    vector<ll> vals(n);
    for(int i=0;i<n;++i){
        cin>>h[i];
        s.insert(h[i]);
    }
    for(int i=0;i<n;++i)cin>>vals[i];
    vector<ll> palst(n,0);
    SegTree st;
    st.build(palst, n);
    for(int i=0;i<n;++i){
        int id=s.order_of_key(h[i]);
        ll tmp=(id==0?0:st.get(0,id-1));
        st.set(id, tmp+vals[i]);
    }
    cout<<st.get(0,n-1)<<"\n";
    return 0;
}
