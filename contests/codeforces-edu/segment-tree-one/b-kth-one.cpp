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
	Node null;

	Node oper(Node a, Node b){
        return {a.val+b.val, a.id};
    }

    Node single(int v,int id){
        return {v,id};
    }

	void build(vector<int>& a, int x, int lx, int rx){
		if(rx-lx==1){
			if(lx<(int)a.size()){
				vals[x]=single(a[lx], lx);
			}
			return;
		}
		int m=(lx+rx)/2;
		build(a, 2*x+1, lx, m);
		build(a, 2*x+2, m, rx);
		vals[x]=oper(vals[2*x+1], vals[2*x+2]);
	}

	void build(vector<int>& a,int n,Node v){
        size=1;
        null=v;
		while(size<n)size*=2;
		vals.resize(2*size);
		build(a, 0, 0, size);
	}

	void set(int i, int x, int lx, int rx){
		if(rx-lx==1){
			vals[x]=single((vals[x].val+1)%2,i);
			return;
		}
		int m=(lx+rx)/2;
		if(i<m){
			set(i,2*x+1,lx,m);
		}else{
			set(i,2*x+2,m,rx);
		}
		vals[x]=oper(vals[2*x+1], vals[2*x+2]);
	}

	void set(int i){
		set(i,0,0,size);
	}

	Node get(int a, int x, int lx, int rx){
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
    vector<int> nums(n);
    for(int i=0;i<n;++i)cin>>nums[i];
    SegTree st;
    st.build(nums, n, {0,0});
    int op,a;
    while(q--){
        cin>>op>>a;
        if(op==1){
            st.set(a);
        }else{
            cout<<st.get(a).id<<"\n";
        }
    }
    return 0;
}
