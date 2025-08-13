typedef long long T;
struct SegTree{
	vector<T> v;
	T null=0;
	int n;
	T op(T a, T b){return a+b;}
	SegTree(int _n){n=_n;v.assign(2*_n,null);}
	SegTree(vector<T>& a){
		n=sz(a);v.assign(2*n, null);
		for(int i=0;i<n;i++)v[n+i]=a[i];
		for(int i=n-1;i>=1;--i)v[i]=op(v[i<<1],v[i<<1|1]);
	}
	void set(int k, T nv){
		for(v[k+=n]=nv;k>1;k>>= 1)
			v[k>>1]=op(v[k], v[k^1]);
	}
	T get(int l, int r){
		T vl=null,vr=null;
		for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
			if(l&1)vl=op(vl,v[l++]);
			if(r&1)vr=op(v[--r],vr);
		}
		return op(vl, vr);
	}
};
