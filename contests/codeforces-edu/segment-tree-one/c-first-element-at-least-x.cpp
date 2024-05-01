// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

struct SegTree{
	int size;
	vector<int> vals;
	int null;

	int oper(int a, int b){
        return max(a,b);
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

	void build(vector<int>& a,int n,int v){
        size=1;
        null=v;
		while(size<n)size*=2;
		vals.resize(2*size);
		build(a, 0, 0, size);
	}

	void set(int i,int v, int x, int lx, int rx){
		if(rx-lx==1){
			vals[x]=v;
			return;
		}
		int m=(lx+rx)/2;
		if(i<m){
			set(i,v,2*x+1,lx,m);
		}else{
			set(i,v,2*x+2,m,rx);
		}
		vals[x]=oper(vals[2*x+1], vals[2*x+2]);
	}

	void set(int i,int v){
		set(i,v,0,0,size);
	}

	int get(int a, int x, int lx, int rx){
        if(rx-lx==1){
            if(vals[x]>=a)return lx;
            return -1;
        }
		int m=(lx+rx)/2;
        if(vals[2*x+1]<a){
            return get(a, 2*x+2, m, rx);
        }
        return get(a, 2*x+1, lx, m);
	}

	int get(int a){
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
    st.build(nums, n, INT_MIN);
    int op,a,b;
    while(q--){
        cin>>op>>a;
        if(op==1){
            cin>>b;
            st.set(a,b);
        }else{
            cout<<st.get(a)<<"\n";
        }
    }
    return 0;
}
