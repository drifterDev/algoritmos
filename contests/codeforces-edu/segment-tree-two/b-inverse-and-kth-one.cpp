// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val,id;
};

struct SegTree{
	int size;
	vector<Node> vals;
	vector<int> lazy;
    int noVal=0;
	Node null={0,INT_MAX};

	Node oper(Node a, Node b){
        return {a.val+b.val, min(a.id, b.id)};
    }

    Node oper2(Node v1, int v2, int len){
        if(v2%2==0)return v1;
        return {len-v1.val, v1.id};
    }

	void build(int x, int lx, int rx){
		if(rx-lx==1){
			vals[x]={0, lx};
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
        lazy.assign(2*size, 0);
		build(0, 0, size);
	}

    void propagate(int x, int lx, int rx){
        if(rx-lx==1)return;
        if(lazy[x]==noVal)return;
        int m=(lx+rx)/2;
        lazy[2*x+1]+=lazy[x];
        vals[2*x+1]=oper2(vals[2*x+1], lazy[x], m-lx);
        lazy[2*x+2]+=lazy[x]; 
        vals[2*x+2]=oper2(vals[2*x+2], lazy[x], rx-m);
        lazy[x]=noVal;
    }

    void upd(int l, int r, int x, int lx, int rx){
        propagate(x,lx,rx);
		if(lx>=r || l>=rx)return;
		if(lx>=l && rx<=r){
            lazy[x]++;
			vals[x]=oper2(vals[x],1,rx-lx);
            return;
        }
		int m=(lx+rx)/2;
		upd(l,r,2*x+1,lx,m);
		upd(l,r,2*x+2,m,rx);
		vals[x]=oper(vals[2*x+1], vals[2*x+2]);
	}

	void upd(int l, int r){
        upd(l,r+1,0,0,size);
	}

	Node get(int a, int x, int lx, int rx){
        propagate(x, lx, rx);
        if(rx-lx==1){
            return vals[x];
        }
		int m=(lx+rx)/2;
        if(vals[2*x+1].val<=a){
            return get(a-vals[2*x+1].val, 2*x+2, m, rx);
        }
        return get(a, 2*x+1, lx, m);
	}

	Node get(int a){
		return get(a,0,0,size);
	}
};

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    SegTree st;
    st.build(n);
    int op,l,r,i;
    while(q--){
        cin>>op;
        if(op==1){
            cin>>l>>r;
            st.upd(l,r-1);
        }else{
            cin>>i;
            cout<<st.get(i).id<<"\n";
        }
    }
    return 0;
}
