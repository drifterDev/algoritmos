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
	Node null;

	Node oper(Node a, Node b){
        return {
            max({a.seg, b.seg, a.suf+b.pref}),
            max(a.pref, a.sum+b.pref),
            max(b.suf, b.sum+a.suf),
            a.sum+b.sum
        };
    }

    Node single(ll v){
        if(v<0)return {0,0,0,v};
        return {v,v,v,v};
    }

	void build(vector<ll>& a, int x, int lx, int rx){
		if(rx-lx==1){
			if(lx<(int)a.size()){
				vals[x]=single(a[lx]);
			}
			return;
		}
		int m=(lx+rx)/2;
		build(a, 2*x+1, lx, m);
		build(a, 2*x+2, m, rx);
		vals[x]=oper(vals[2*x+1], vals[2*x+2]);
	}

	void build(vector<ll>& a,int n,Node v){
        size=1;
        null=v;
		while(size<n)size*=2;
		vals.resize(2*size);
		build(a, 0, 0, size);
	}

	void set(int i, ll val, int x, int lx, int rx){
		if(rx-lx==1){
			vals[x]=single(val);
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

	Node get(int l, int r, int x, int lx, int rx){
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
    vector<ll> nums(n);
    for(int i=0;i<n;++i)cin>>nums[i];
    SegTree st;
    st.build(nums, n, {0,0,0,0});
    int a;
    ll tmp,it=st.get(0,n-1).seg;
    while(q--){
        cout<<it<<"\n";
        cin>>a>>tmp;
        st.set(a, tmp);
        it=st.get(0,n-1).seg;
    }
    cout<<it<<"\n";
    return 0;
}
