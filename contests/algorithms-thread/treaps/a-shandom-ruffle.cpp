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

struct Treap{
	Treap *l,*r,*dad;
	u64 prior;
	T sz,value,sum;
	bool lz;
	Treap(T v){
		l=r=nullptr;
		lz=false;
		prior=rng();
		sz=1;
		value=sum=v;
	}

	~Treap(){
		delete l;
		delete r;
	}
};

typedef Treap* PTreap;
T cnt(PTreap x){return (!x?0:x->sz);}
T sum(PTreap x){return (!x?0:x->sum);}

void propagate(PTreap x){
	if(x && x->lz){
		swap(x->l, x->r);
		if(x->l)x->l->lz=!x->l->lz;
		if(x->r)x->r->lz=!x->r->lz;
		x->lz=false;
	}
}

void update(PTreap x){
	propagate(x->l);
	propagate(x->r);
	x->sz=cnt(x->l)+cnt(x->r)+1;
	x->sum=sum(x->l)+sum(x->r)+x->value;
	if(x->l)x->l->dad=x;
	if(x->r)x->r->dad=x;
}

void inverse(PTreap x){
	if(!x)return;
	x->lz=true;
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

void dfs(PTreap x){
	if(!x)return;
	propagate(x);
	dfs(x->l);
	cout<<x->value<<" ";
	dfs(x->r);
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	PTreap root=nullptr;
	int n;cin>>n;
	for(int i=1;i<=n;++i){
		PTreap tmp=new Treap(i);
		root=merge(root, tmp);
	}
	for(int a,b,i=0;i<n;++i){
		cin>>a>>b;
		if(a>=b)continue;
		int c=min(b-a, n-b+1);
		auto r1=split(root, b+c-1);
		auto r2=split(r1.first, b-1);
		auto r3=split(r2.first, a+c-1);
		auto r4=split(r3.first, a-1);
		root=merge(r4.first, merge(r2.second, merge(r3.second, merge(r4.second, r1.second))));
	}
	dfs(root);cout<<"\n";
	return 0;
}
