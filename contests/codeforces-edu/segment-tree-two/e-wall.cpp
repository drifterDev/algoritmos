// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node{
    ll min,max;
};

struct SegTree{
	int size;
	vector<Node> vals;
	vector<pair<ll,ll>> lazy;
    pair<ll,ll> noVal={LLONG_MIN, LLONG_MAX};
	Node null={LLONG_MAX, LLONG_MIN};

	Node oper(Node a, Node b){
        return {min(a.min, b.min), max(a.max, b.max)};
    }

    void oper2(int x, ll v, int op){
        if(op==1){
            vals[x].min=v;
            vals[x].max=max(vals[x].max, v);
            lazy[x].first=v;
            lazy[x].second=max(lazy[x].second, v);
        }else{
            vals[x].max=v;
            vals[x].min=min(vals[x].min, v);
            lazy[x].second=v;
            lazy[x].first=min(lazy[x].first, v);
        }
    }

	void build(int x, int lx, int rx){
		if(rx-lx==1){
			vals[x]={0,0};
			return;
		}
		int m=(lx+rx)/2;
		build(2*x+1, lx, m);
		build(2*x+2, m, rx);
		vals[x]=oper(vals[2*x+1], vals[2*x+2]);
	}

	void build(int n){
        size=1;
		while(size<n)size*=2;
		vals.resize(2*size);
        lazy.assign(2*size, noVal);
		build(0, 0, size);
	}

    void propagate(int x, int lx, int rx){
        if(rx-lx==1)return;
        ll v=lazy[x].first;
        if(vals[2*x+1].min<v)oper2(2*x+1, v, 1);
        if(vals[2*x+2].min<v)oper2(2*x+2, v, 1);
        v=lazy[x].second;
        if(vals[2*x+1].max>v)oper2(2*x+1, v, 2);
        if(vals[2*x+2].max>v)oper2(2*x+2, v, 2);
        lazy[x]=noVal;
    }

    void upd(int l, int r, ll v,int x, int lx, int rx,int op){
        propagate(x,lx,rx);
		if(lx>=r || l>=rx)return;
		if(lx>=l && rx<=r){
            if(op==1){
                if(vals[x].min>=v)return;
                oper2(x, v, 1);
            }else{
                if(vals[x].max<=v)return;
                oper2(x, v, 2);
            }   
            return;
        }
		int m=(lx+rx)/2;
		upd(l,r,v,2*x+1,lx,m,op);
		upd(l,r,v,2*x+2,m,rx,op);
		vals[x]=oper(vals[2*x+1], vals[2*x+2]);
	}

	void upd(int l, int r, ll v,int op){
        upd(l,r+1,v,0,0,size,op);
	}

	Node get(int l, int r, int x, int lx, int rx){
        propagate(x,lx,rx);
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
    SegTree st;
    st.build(n);
    int op,l,r;
    ll v;
    while(q--){
        cin>>op>>l>>r>>v;
        st.upd(l,r,v,op);
    }
    for(int i=0;i<n;++i){
        cout<<st.get(i,i).max<<"\n";
    }
    return 0;
}
