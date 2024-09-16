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
	Treap(T v){
		l=r=nullptr;
		dad=nullptr;
		sum=value=v;
		prior=rng();
		sz=1;
	}

	~Treap(){
		delete l;
		delete r;
	}
};

typedef Treap* PTreap;
T cnt(PTreap x){return (!x?0:x->sz);}
T sum(PTreap x){return (!x?0:x->sum);}
PTreap dad(PTreap x){
	if(!x)return nullptr;
	if(x->dad==nullptr)return x;
	return dad(x->dad);
}

void update(PTreap x){
	x->sz=cnt(x->l)+cnt(x->r)+1;
	x->sum=sum(x->l)+sum(x->r)+x->value;
	if(x->l)x->l->dad=x;
	if(x->r)x->r->dad=x;
}

pair<PTreap, PTreap> split(PTreap x, int left){ 
	if(!x)return {nullptr, nullptr};
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
	int q;cin>>q;
	int op,y,z;
	map<int, PTreap> mp;
	for(int i=1;i<=q;++i){
		cin>>op>>y;
		if(op==1){
			mp[i]=new Treap(y);
		}else if(op==2){
			cin>>z;
			PTreap d1=dad(mp[y]);
			PTreap d2=dad(mp[z]);
			if(d1==d2)continue;
			PTreap tmp=merge(d1, d2);
			tmp->dad=nullptr;
		}else if(op==3){
			cin>>z;
			PTreap d1=dad(mp[y]);
			if(cnt(d1)<=z)continue;
			auto r=split(d1, z);
			r.first->dad=nullptr;
			r.second->dad=nullptr;
		}else{
			cout<<sum(dad(mp[y]))<<"\n";
		}
	}
	return 0;
}
