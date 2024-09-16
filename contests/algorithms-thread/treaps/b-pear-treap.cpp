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
#define F first
#define S second
const int MOD[2] = { 1001864327, 1001265673 }; // 1000234999, 1000567999, 1000111997, 1000777121, 1001265673, 1001864327, 999727999, 1070777777
const ii BASE(257, 367), ZERO(0, 0), ONE(1, 1);
const int MAXN = 1e6;

inline int add(int a, int b, int mod){return a+b >= mod ? a+b-mod : a+b;}
inline int sbt(int a, int b, int mod){return a-b < 0 ? a-b+mod : a-b;}
inline int mul(int a, int b, int mod){return ll(a) * b % mod;} 
inline ll operator ! (const ii a){return (ll(a.F) << 32) | a.S;}
inline ii operator + (const ii& a, const ii& b){return {add(a.F, b.F, MOD[0]), add(a.S, b.S, MOD[1])};}
inline ii operator - (const ii& a, const ii& b){return {sbt(a.F, b.F, MOD[0]), sbt(a.S, b.S, MOD[1])};}
inline ii operator * (const ii& a, const ii& b){return {mul(a.F, b.F, MOD[0]), mul(a.S, b.S, MOD[1])};}

ii p[MAXN+1];
void prepare(){
	p[0]=ONE;
	for(int i=1;i<=MAXN;i++)p[i]=p[i-1]*BASE;
}

// Acordate del prepare()!!
template <class type> 
struct hashing {
	vector<ii> h;
	hashing(type &t) {
		h.resize((int)t.size()+1);
		h[0]=ZERO;
		for (int i=1;i<(int)h.size();++i)
			h[i]=h[i-1]*BASE + ii{t[i-1], t[i-1]};
	}

	ii get(int l, int r){
		return h[r+1]-h[l]*p[r-l+1];
	}
};

ii combine(ii a, ii b, int lenb){
	return a*p[lenb]+b;
}

typedef long long T;
typedef unsigned long long u64;
mt19937_64 rng (chrono::steady_clock::now().time_since_epoch().count());

struct Treap{
	Treap *l,*r,*dad;
	u64 prior;
	T sz;
	char value;
	ii hs1,hs2;
	Treap(char v){
		l=r=nullptr;
		prior=rng();
		sz=1;
		value=v;
		hs1=hs2={v, v};
	}

	~Treap(){
		delete l;
		delete r;
	}
};

typedef Treap* PTreap;
T cnt(PTreap x){return (!x?0:x->sz);}

void updateHS(PTreap x){
	x->hs1=x->hs2={x->value, x->value};

	if(x->l)x->hs1=combine(x->l->hs1, x->hs1, 1);
	if(x->r)x->hs1=combine(x->hs1, x->r->hs1, cnt(x->r));

	if(x->r)x->hs2=combine(x->r->hs2, x->hs2, 1);
	if(x->l)x->hs2=combine(x->hs2, x->l->hs2, cnt(x->l));
}

void update(PTreap x){
	x->sz=cnt(x->l)+cnt(x->r)+1;
	updateHS(x);
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

void dfs(PTreap x){
	if(!x)return;
	dfs(x->l);
	cout<<x->value<<" ";
	dfs(x->r);
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	prepare();
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
		cin>>op;
		if(op==1){
			cin>>l>>r;
			auto r1=split(root, r);
			auto r2=split(r1.first, l-1);
			root=merge(r2.first, r1.second);
			delete r2.second;
		}else if(op==2){
			cin>>c>>l;
			auto r1=split(root, l-1);
			PTreap tmp=new Treap(c);
			root=merge(r1.first, merge(tmp, r1.second));
		}else{
			cin>>l>>r;
			auto r1=split(root, r);
			auto r2=split(r1.first, l-1);
			update(r2.second);
			bool f=r2.second->hs1==r2.second->hs2;
			cout<<(f?"yes":"no")<<"\n";
			root=merge(r2.first, merge(r2.second, r1.second));
		}
	}
	return 0;
}
