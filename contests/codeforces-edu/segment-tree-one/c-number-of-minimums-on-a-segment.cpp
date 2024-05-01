// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

template<typename T> struct SegTree{
	int size;
	vector<T> vals;
	T null;

	T oper(T a, T b){
        if(a.first<b.first){
            return a;
        }else if(a.first>b.first){
            return b;
        }else{
            return {a.first, a.second+b.second};
        }
    }

	void build(vector<T>& a, int x, int lx, int rx){
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

	void build(vector<T>& a,int n,T v){
        size=1;
        null=v;
		while(size<n)size*=2;
		vals.assign(2*size, {0,0});
		build(a, 0, 0, size);
	}

	void set(int i, T val, int x, int lx, int rx){
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

	void set(int i, T val){
		set(i,val,0,0,size);
	}

	T get(int l, int r, int x, int lx, int rx){
		if(lx>=r || l>=rx)return null;
		if(lx>=l && rx<=r)return vals[x];
		int m=(lx+rx)/2;
		T v1=get(l,r,2*x+1,lx,m);
		T v2=get(l,r,2*x+2,m,rx);
		return oper(v1,v2);
	}

	T get(int l, int r){
		return get(l,r+1,0,0,size);
	}
};

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    vector<pair<int,int>> nums(n, {0,1});
    for(int i=0;i<n;++i)cin>>nums[i].first;
    SegTree<pair<int,int>> st;
    st.build(nums, n, {INT_MAX, 0});
    int op,a,b;
    while(q--){
        cin>>op>>a>>b;
        if(op==1){
            st.set(a,{b,1});
        }else{
            pair<int,int> it=st.get(a,b-1);
            cout<<it.first<<" "<<it.second<<"\n";
        }
    }
    return 0;
}
