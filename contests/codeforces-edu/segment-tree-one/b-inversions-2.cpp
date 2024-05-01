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
        return a+b;
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

	int get(int a, int x, int lx, int rx){
        if(rx-lx==1)return lx+1;
		int m=(lx+rx)/2;
        int val=vals[2*x+2];
        if(a>=val)return get(a-val, 2*x+1, lx, m);
        return get(a,2*x+2,m,rx);
	}

	int get(int a){
		return get(a,0,0,size);
	}
};

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n;cin>>n;
    SegTree st;
    vector<int> nums(n,1);
    st.build(nums, n, 0);
    vector<int> p(n);
    for(int i=0;i<n;++i)cin>>p[i];
    for(int i=n-1;i>=0;--i){
        p[i]=st.get(p[i]);
        st.set(p[i]-1, 0);
    }
    for(auto x:p)cout<<x<<" ";
    return 0;
}

