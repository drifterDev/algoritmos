// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

struct SegTree{
	int size;
	vector<int> vals;
	int null=INT_MAX;

	int oper(int a, int b){
        return min(a,b);
    }

	void build(vector<int>& a, int x, int lx, int rx){
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

	void build(vector<int>& a,int n){
        size=1;
		while(size<n)size*=2;
		vals.resize(2*size);
		build(a, 0, 0, size);
	}

	void set(int i, int val, int x, int lx, int rx){
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

	void set(int i, int val){
		set(i,val,0,0,size);
	}

	int get(int l, int r,int v, int x, int lx, int rx){
		if(lx>=r || l>=rx)return 0;
		if(rx-lx==1){
            if(vals[x]<=v){
                vals[x]=null;
                return 1;
            }
            return 0;
        }
        int m=(lx+rx)/2;
        int ans=0;
        if(vals[2*x+1]<=v)ans+=get(l,r,v,2*x+1,lx,m);
        if(vals[2*x+2]<=v)ans+=get(l,r,v,2*x+2,m,rx);
		vals[x]=oper(vals[2*x+1], vals[2*x+2]);
        return ans;
	}

	int get(int l, int r, int c){
        return get(l,r+1,c,0,0,size);
	}
};

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    vector<int> p(n,INT_MAX);
    SegTree st;
    st.build(p, n);
    int op,a,b,c;
    while(q--){
        cin>>op>>a>>b;
        if(op==1){
            st.set(a,b);
        }else{
            cin>>c;
            cout<<st.get(a,b-1,c)<<"\n";
        }
    }
    return 0;
}
