// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define S second
#define F first
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
ll nullValue=0;

struct NodeST{
	NodeST *left,*right;
	int l,r, resl, resr,l1,r1,l2,r2;ll gV,rV,lV,sV;
	NodeST(vi &v,int l,int r):l(l),r(r){
		int m=(l+r)>>1;
		if(l!=r){
			left=new NodeST(v, l, m);
			right=new NodeST(v, m+1, r);
			opt(left, right);
		}
		else{
			gV=rV=lV=sV=v[l];
			resl=resr=l;
			l1=r1=r2=l2=l;
		}
	}

	void opt(NodeST *left, NodeST *right){
		gV=max(left->gV, right->gV);
		gV=max(gV, left->rV+right->lV);
		lV=max(left->lV, left->sV+right->lV);
		rV=max(right->rV, right->sV+left->rV);
		sV=left->sV+right->sV;

		if(left->gV==gV){
			resl=left->resl;
			resr=left->resr;
		}else if(right->gV==gV){
			resl=right->resl;
			resr=right->resr;
		}else{
			resl=left->l2;
			resr=right->r1;
		}

		if(left->lV==lV){
			l1=left->l1;
			r1=left->r1;
		}else{
			l1=left->l;
			r1=right->r1;
		}

		if(right->rV==rV){
			l2=right->l2;
			r2=right->r2;
		}else{
			l2=left->l2;
			r2=right->r;
		}
	}

	pair<ll, ii> get(){
		return {gV,{resl,resr}};
	}

	void upd(int i, int j, int nv){
		if(l>j || r<i)return;
		if(l==r){
			gV=rV=lV=sV=nv;
			resl=resr=l;
			l1=r1=r2=l2=l;
			return;
		}
		left->upd(i,j,nv);
		right->upd(i,j,nv);
		opt(left, right);
	}

	void upd(int k, int nv){
		if(l==r){
			gV=rV=lV=sV=nv;
			resl=resr=l;
			l1=r1=r2=l2=l;
			return;
		}
		if(k<=left->r)left->upd(k,nv);
		else right->upd(k,nv);
		opt(left, right);
	}
};

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,q;cin>>n>>q;
	vi v(n);
	for(int i=0;i<n;i++)cin>>v[i];
	NodeST st(v,0,n-1);
	while(q--){
		int a,b;cin>>a>>b;
		st.upd(a-1,b);
		auto x=st.get();
		cout<<x.F<<" "<<x.S.F+1<<" "<<x.S.S+1<<"\n";
	}
	return 0;
}