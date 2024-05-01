// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

struct SegTree{
	int size;
	vector<int> vals;
	int null=0;

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
    int n,m;
    cin>>n>>m;
    vector<int> nums2(n);
    vector<vector<int>> nums(40, vector<int>(n,0));
    for(int a,i=0;i<n;++i){
        cin>>a;
        a--;
        nums2[i]=a;
        nums[a][i]=1;
    }
    vector<SegTree> sts;
    for(int i=0;i<40;++i){
        SegTree st;
        st.build(nums[i], n);
        sts.push_back(st);
    }
    int op,a,b;
    while(m--){
        cin>>op>>a>>b;
        a--;b--;
        if(op==1){
            int ans=0;
            for(int i=0;i<40;++i){
                ans+=min(1, sts[i].get(a,b));
            }
            cout<<ans<<"\n";
        }else{
            int c=nums2[a];
            sts[c].set(a,0);
            nums2[a]=b;
            sts[b].set(a,1);
        }
    }
    return 0;
}
