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
	ll null=0ll;

	ll oper(ll a, ll b){
        return a+b;
    }

	void build(vector<ll>& a, int x, int lx, int rx){
		if(rx-lx==1){
			if(lx<(int)a.size()){
                vals[x]=(lx%2==0?a[lx]:-a[lx]);
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
			vals[x]=(lx%2==0?val:-val);
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
		ll ans=get(l,r+1,0,0,size);
        return (l%2==0?ans:-ans);
	}
};

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n;
    cin>>n;
    vector<ll> nums(n);
    for(int i=0;i<n;++i)cin>>nums[i];
    SegTree st;
	st.build(nums, n);
	int q;
	cin>>q;
	int op,a,b;
	ll c;
	while(q--){
		cin>>op>>a;
		if(op==1){
			cin>>b;
			cout<<st.get(a-1,b-1)<<"\n";
		}else{
			cin>>c;
			st.set(a-1,c);
		}
	}
    return 0;
}
