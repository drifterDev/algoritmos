// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int num,sz,l,r;
};

struct SegTree{
	int size;
	vector<Node> vals;
	vector<int> lazy;
    int noVal=-1;
	Node null={-1,-1,-1,-1};

	Node oper(Node a, Node b){
        if(a.num==-1)return b;
        if(b.num==-1)return a;
        int tmp=0;
        if(a.r && b.l)tmp++;
        return {
            a.num+b.num-tmp,
            a.sz+b.sz,
            a.l,
            b.r
        };
    }

    void oper2(int x,int len,int op){
		if(op==2)vals[x]={1,len,1,1};
        else vals[x]={0,0,0,0};
    }

	void build(int x, int lx, int rx){
		if(rx-lx==1){
			vals[x]={0,0,0,0};
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
        lazy[2*x+1]=lazy[2*x+2]=lazy[x];
        oper2(2*x+1,m-lx,lazy[x]);
        oper2(2*x+2,rx-m,lazy[x]);
        lazy[x]=noVal;
    }

    void upd(int l, int r, int x, int lx, int rx,int op){
        propagate(x,lx,rx);
		if(lx>=r || l>=rx)return;
		if(lx>=l && rx<=r){
            lazy[x]=op;
            oper2(x,rx-lx,op);
            return;
        }
		int m=(lx+rx)/2;
		upd(l,r,2*x+1,lx,m,op);
		upd(l,r,2*x+2,m,rx,op);
		vals[x]=oper(vals[2*x+1], vals[2*x+2]);
	}

	void upd(int l, int r,int op){
        upd(l,r+1,0,0,size,op);
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
    int q;
    cin>>q;
    SegTree st;
    st.build(1000005);
    char c;
    int l,r;
    while(q--){
        cin>>c>>l>>r;
        if(r)st.upd(l+500000,l+r-1+500000,(c=='W'?1:2));
        Node ans=st.get(0,1000004);
        cout<<max(0,ans.num)<<" "<<max(0,ans.sz)<<"\n";
    }
    return 0;
}
