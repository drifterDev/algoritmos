// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

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

typedef long long T;
typedef unsigned long long u64;
mt19937_64 rng (chrono::steady_clock::now().time_since_epoch().count());

T inf = 1e18;
struct Treap{
	Treap *l,*r,*dad;
	u64 prior;
	T sz,value,sum,lz;
	T max1,max2,maxc;
	Treap(T v){
		l=r=nullptr;
		lz=false;
		prior=rng();
		sz=maxc=1;
		value=sum=max1=v;
		max2=-inf;
		lz=0;
	}

	~Treap(){
		delete l;
		delete r;
	}
};

typedef Treap* PTreap;
T cnt(PTreap x){return (!x?0:x->sz);}
T sum(PTreap x){return (!x?0:x->sum);}

void propagateMax(PTreap x, T v){
	if(!x)return;
	if(x->max1<=v)return;
	x->sum-=x->max1*x->maxc;
	x->max1=v;
	x->value=min(x->value, v);
	x->sum+=x->max1*x->maxc;
}

void propagate(PTreap x){
	if(!x)return;
	if(x->lz){
		if(x->l){
			x->l->lz+=x->lz;
			x->l->value+=x->lz;
			x->l->max1+=x->lz;
			if(x->l->max2!=-inf)x->l->max2+=x->lz;
			x->l->sum+=x->lz*cnt(x->l);
		}
		if(x->r){
			x->r->lz+=x->lz;
			x->r->value+=x->lz;
			x->r->max1+=x->lz;
			if(x->r->max2!=-inf)x->r->max2+=x->lz;
			x->r->sum+=x->lz*cnt(x->r);
		}
		x->lz=0;
	}

	propagateMax(x->l, x->max1);
	propagateMax(x->r, x->max1);
}

void updateMax(PTreap x){
	map<T, T, greater<T>> mp;
	mp[x->value]++;
	mp[-inf]++;
	if(x->l){
		mp[x->l->max1]+=x->l->maxc;
		mp[x->l->max2]++;
	}
	if(x->r){
		mp[x->r->max1]+=x->r->maxc;
		mp[x->r->max2]++;
	}
	x->max1=mp.begin()->first;
	x->maxc=mp.begin()->second;
	x->max2=next(mp.begin())->first;
}

void update(PTreap x){
	propagate(x->l);
	propagate(x->r);
	x->sz=cnt(x->l)+cnt(x->r)+1;
	x->sum=sum(x->l)+sum(x->r)+x->value;
	updateMax(x);
	if(x->l)x->l->dad=x;
	if(x->r)x->r->dad=x;
}

void add(PTreap x, T v){
	if(!x)return;
	update(x);
	x->lz+=v;
	x->value+=v;
	x->sum+=v*cnt(x);
	x->max1+=v;
	if(x->max2!=-inf)x->max2+=v;
}

void upd(PTreap x, T v){
	if(!x)return;
	propagate(x);
	if(x->max1<=v)return;
	if(x->max2<v){
		propagateMax(x, v);
		return;
	}
	x->value=min(x->value, v);
	upd(x->l, v);
	upd(x->r, v);
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
	int n,q;cin>>n>>q;
	PTreap root=nullptr;
	ll v;
	for(int i=0;i<n;++i){
		cin>>v;
		PTreap tmp=new Treap(v);
		root=merge(root, tmp);
	}
	int op,l,r;
	while(q--){
		cin>>op>>l>>r;
		if(op==1){
			cin>>v;
			auto r1=split(root, r);
			auto r2=split(r1.first, l-1);
			upd(r2.second, v);
			root=merge(r2.first, merge(r2.second, r1.second));
		}else if(op==2){
			auto r1=split(root, r);
			auto r2=split(r1.first, l-1);
			root=merge(r2.first, merge(r1.second, r2.second));
		}else{
			cin>>v;
			auto r1=split(root, r);
			auto r2=split(r1.first, l-1);
			add(r2.second, v);
			root=merge(r2.first, merge(r2.second, r1.second));
		}
		cout<<sum(root)<<"\n";
	}
	return 0;
}
