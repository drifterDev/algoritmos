// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node{
    ll m,i,inv;
};

struct SegTree{
	int size,num;
	vector<Node> vals;
	Node null={0,0,0};

	Node oper(Node a, Node b){
        return {
            a.m+b.m,
            a.i+b.i,
            b.inv+(a.i*b.m)+a.inv
        };
    }

    Node single(int v){
        if(v<num)return {1,0,0};
        if(v==num)return {0,1,0};
        return null;
    }

	void build(vector<int>& a, int x, int lx, int rx){
		if(rx-lx==1){
			if(lx<(int)a.size()){
				vals[x]=single(a[lx]);
			}
			return;
		}
		int m=(lx+rx)/2;
		build(a, 2*x+1, lx, m);
		build(a, 2*x+2, m, rx);
		vals[x]=oper(vals[2*x+1], vals[2*x+2]);
	}

	void build(vector<int>& a,int n,int val){
        size=1;
        num=val;
		while(size<n)size*=2;
		vals.resize(2*size);
		build(a, 0, 0, size);
	}

	void set(int i, int val, int x, int lx, int rx){
		if(rx-lx==1){
			vals[x]=single(val);
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

	void set(int i, ll val){
		set(i,val,0,0,size);
	}

	Node get(int l, int r, int x, int lx, int rx){
		if(lx>=r || l>=rx)return null;
		if(lx>=l && rx<=r)return vals[x];
		int m=(lx+rx)/2;
		Node v1=get(l,r,2*x+1,lx,m);
		Node v2=get(l,r,2*x+2,m,rx);
		return oper(v1,v2);
	}

	ll get(int l, int r){
		return get(l,r+1,0,0,size).inv;
	}
};

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    vector<int> nums(n);
    for(int i=0;i<n;++i)cin>>nums[i];
    vector<SegTree> sts;
    for(int i=0;i<40;++i){
        SegTree st;
        st.build(nums, n, i+1);
        sts.push_back(st);
    }
    int op,a,b;
    while(q--){
        cin>>op>>a>>b;
        if(op==1){
            ll ans=0;
            for(int i=0;i<40;++i){
                ans+=sts[i].get(a-1,b-1);
            }
            cout<<ans<<"\n";
        }else{
            for(int i=0;i<40;++i){
                sts[i].set(a-1, b);
            }
        }
    }
    return 0;
}
