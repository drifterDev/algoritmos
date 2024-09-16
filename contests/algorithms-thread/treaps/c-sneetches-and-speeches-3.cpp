#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"
#define watch(x) cout<<#x<<"="<<x<<"\n"
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

typedef int T;
typedef unsigned long long u64;
mt19937_64 rng (chrono::steady_clock::now().time_since_epoch().count());

struct Treap{
	Treap *l,*r,*dad;
	u64 prior;
	T sz,suf1,pre1,suf0,pre0,ans,c1,c0;
	bool lz,ch,val,ord;
	Treap(char c){
		l=r=nullptr;
		dad=nullptr;
		prior=rng();
		suf1=pre1=suf0=pre0=0;
		if(c=='1')suf1=pre1=1;
		else suf0=pre0=1;
		c1=c0=0;
		val=(c=='1');
		if(c=='1')c1++;
		else c0++;
		sz=ans=1;
		lz=ch=ord=false;
	}

	~Treap(){
		delete l;
		delete r;
	}
};

typedef Treap* PTreap;
T cnt(PTreap x){return (!x?0:x->sz);}
T c1(PTreap x){return (!x?0:x->c1);}
T c0(PTreap x){return (!x?0:x->c0);}
T suf0(PTreap x){return (!x?0:x->suf0);}
T suf1(PTreap x){return (!x?0:x->suf1);}
T pre0(PTreap x){return (!x?0:x->pre0);}
T pre1(PTreap x){return (!x?0:x->pre1);}
T ans(PTreap x){return (!x?0:x->ans);}

void updateSuf(PTreap x){
	x->suf1=suf1(x->r);
	x->suf0=suf0(x->r);
	if(x->val && suf1(x->r)==cnt(x->r))x->suf1=cnt(x->r)+1+suf1(x->l);
	if(!x->val && suf0(x->r)==cnt(x->r))x->suf0=cnt(x->r)+1+suf0(x->l);
}

void updatePre(PTreap x){
	x->pre1=pre1(x->l);
	x->pre0=pre0(x->l);
	if(x->val && pre1(x->l)==cnt(x->l))x->pre1=cnt(x->l)+1+pre1(x->r);
	if(!x->val && pre0(x->l)==cnt(x->l))x->pre0=cnt(x->l)+1+pre0(x->r);
}

void updateAns(PTreap x){
	x->ans=max({1, ans(x->l), ans(x->r), pre1(x), pre0(x), suf1(x), suf0(x)});
	if(x->val)x->ans=max({x->ans, 1+suf1(x->l)+pre1(x->r)});
	if(!x->val)x->ans=max({x->ans, 1+suf0(x->l)+pre0(x->r)});
}

void propagate(PTreap x){
	if(x && x->ord){
		int unos=c1(x);
		int ceros=c0(x);
		x->suf0=x->pre1=0;
		x->suf1=unos;
		x->pre0=ceros;
		if(!ceros)x->pre1=unos;
		if(!unos)x->suf0=ceros;
		x->ans=max(unos, ceros);
		if(x->l){
			x->l->ord=true;
			x->l->ch=x->l->lz=false;
			x->l->c0=min(ceros, cnt(x->l));
			x->l->c1=cnt(x->l)-x->l->c0;
			ceros-=x->l->c0;
			unos-=x->l->c1;
		}
		if(ceros){
			x->val=false;
			ceros--;
		}else{
			x->val=true;
			unos--;
		}
		if(x->r){
			x->r->ord=true;
			x->r->ch=x->r->lz=false;
			x->r->c0=ceros;
			x->r->c1=unos;
		}
		x->ord=false;
	}

	if(x && x->lz){
		swap(x->l, x->r);
		swap(x->pre1, x->suf1);
		swap(x->pre0, x->suf0);
		if(x->l)x->l->lz=!x->l->lz;
		if(x->r)x->r->lz=!x->r->lz;
		x->lz=false;
	}

	if(x && x->ch){
		x->val=!x->val;
		swap(x->pre0, x->pre1);
		swap(x->suf0, x->suf1);
		swap(x->c1, x->c0);
		if(x->l)x->l->ch=!x->l->ch;
		if(x->r)x->r->ch=!x->r->ch;
		x->ch=false;
	}
}

void update(PTreap x){
	propagate(x->l);
	propagate(x->r);
	x->sz=cnt(x->l)+cnt(x->r)+1;
	x->c1=c1(x->l)+c1(x->r)+x->val;
	x->c0=c0(x->l)+c0(x->r)+!x->val;
	updateSuf(x);
	updatePre(x);
	updateAns(x);
	if(x->l)x->l->dad=x;
	if(x->r)x->r->dad=x;
}

void inverse(PTreap x){
	if(!x)return;
	x->lz=true;
	update(x);
}

void change(PTreap x){
	if(!x)return;
	x->ch=true;
	update(x);
}

void order(PTreap x){
	if(!x)return;
	x->ord=true;
	x->ch=x->lz=false;
	update(x);
}

pair<PTreap, PTreap> split(PTreap x, int left){ 
	if(!x)return {nullptr, nullptr};
	propagate(x);
	if(cnt(x->l)>=left){ 
		auto got=split(x->l, left); 
		x->l=got.second;
		update(x);
		return {got.first, x};
	}else{
		auto got=split(x->r, left-cnt(x->l)-1); 
		x->r=got.first;
		update(x);
		return {x, got.second};
	}
}

PTreap merge(PTreap x, PTreap y){
	if(!x)return y;
	if(!y)return x;
	propagate(x);
	propagate(y);
	if(x->prior<=y->prior){
		x->r=merge(x->r, y);
		update(x);
		return x;
	}else{
		y->l=merge(x, y->l);
		update(y);
		return y;
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,q;
	cin>>n>>q;
	PTreap root=nullptr;
	char c;
	for(int i=0;i<n;++i){
		cin>>c;
		PTreap tmp=new Treap(c);
		root=merge(root, tmp);
	}
	int op,l,r;
	while(q--){
		cin>>op>>l>>r;
		if(op==1){
			auto r1=split(root, r);
			auto r2=split(r1.first, l-1);
			change(r2.second);
			root=merge(r2.first, merge(r2.second, r1.second));
		}else if(op==2){
			auto r1=split(root, r);
			auto r2=split(r1.first, l-1);
			inverse(r2.second);
			root=merge(r2.first, merge(r2.second, r1.second));
		}else{
			auto r1=split(root, r);
			auto r2=split(r1.first, l-1);
			order(r2.second);
			root=merge(r2.first, merge(r2.second, r1.second));
		}
		propagate(root);
		update(root);
		cout<<ans(root)<<"\n";
	}
	return 0;
}
