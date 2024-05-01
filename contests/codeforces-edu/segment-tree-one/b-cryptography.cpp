// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
int modu;

int mod(int a){
	return ((a%modu)+modu)%modu;
}

int suma(int a, int b){
    return mod(mod(a)+mod(b));
}

int mult(int a, int b){
    return mod(mod(a)*mod(b));
}

struct Node{
    int a1,a2,b1,b2;
};

struct SegTree{
	int size;
	vector<Node> vals;
	Node null={1,0,0,1};

	Node oper(Node a, Node b){
        return {
            suma(mult(a.a1, b.a1), mult(a.a2, b.b1)),
            suma(mult(a.a1, b.a2), mult(a.a2, b.b2)),
            suma(mult(a.b1, b.a1), mult(a.b2, b.b1)),
            suma(mult(a.b1, b.a2), mult(a.b2, b.b2))
        };
    }

	void build(vector<Node>& a, int x, int lx, int rx){
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

	void build(vector<Node>& a,int n){
        size=1;
		while(size<n)size*=2;
		vals.resize(2*size);
		build(a, 0, 0, size);
	}

	Node get(int l, int r, int x, int lx, int rx){
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
    int n,m;
    cin>>modu>>n>>m;
    vector<Node> nums(n);
    int a,b,c,d;
    for(int i=0;i<n;++i){
        cin>>a>>b>>c>>d;
        nums[i]={mod(a),mod(b),mod(c),mod(d)};
    }
    SegTree st;
    st.build(nums, n);
    int l,r;
    while(m--){
        cin>>l>>r;
        Node it=st.get(l-1,r-1);
        cout<<it.a1<<" "<<it.a2<<"\n";
        cout<<it.b1<<" "<<it.b2<<"\n\n";
    }
    return 0;
}
