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

	int get(int l, int r, int x, int lx, int rx){
		if(lx>=r || l>=rx)return null;
		if(lx>=l && rx<=r)return vals[x];
		int m=(lx+rx)/2;
		int v1=get(l,r,2*x+1,lx,m);
		int v2=get(l,r,2*x+2,m,rx);
		return oper(v1,v2);
	}

	int get(int l, int r){
		return get(l,r+1,0,0,size);
	}
};

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> p(n*2,0);
    vector<int> ans(n,0);
    vector<int> segs(n*2);
    vector<int> mp(n,-1),mp2(n,-1);
    SegTree st,st2;
    st.build(p, 2*n, 0);
    st2.build(p, 2*n, 0);
    for(int a,i=0;i<2*n;++i){
        cin>>segs[i];
        if(mp[segs[i]-1]==-1)mp[segs[i]-1]=i;
        else mp2[segs[i]-1]=i;
    }
    for(int i=0;i<2*n;++i){
        if(i==mp2[segs[i]-1])continue;
        ans[segs[i]-1]+=st.get(i,mp2[segs[i]-1]);
        st.set(mp2[segs[i]-1], 1);
    }
    for(int i=2*n-1;i>=0;--i){
        if(i==mp[segs[i]-1])continue;
        ans[segs[i]-1]+=st2.get(mp[segs[i]-1],i);
        st2.set(mp[segs[i]-1], 1);
    }
    for(auto x:ans)cout<<x<<" ";
    return 0;
}
