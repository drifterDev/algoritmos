#include <bits/stdc++.h>
using namespace std;

typedef long long T;
struct SplayTree{
	struct Node{
		int ch[2]={0, 0},p=0;
		int sz=1;
		T val=0,path=0;        	// Path
		T sub=0,vir=0;          // Subtree
		bool flip=0;			// Lazy			
	};
	vector<Node> ns;

	SplayTree(int n):ns(n+1){}

	int size(int u){return (u?ns[u].sz:0);}
	void push(int x){
		if(!x)return;
		int l=ns[x].ch[0],r=ns[x].ch[1];
		if(ns[x].flip){
			ns[l].flip^=1,ns[r].flip^=1;
			swap(ns[x].ch[0], ns[x].ch[1]); // check with st oper
			ns[x].flip=0;
		}
	}
	
	void pull(int x){
		int l=ns[x].ch[0],r=ns[x].ch[1];
		push(l);push(r); 
		ns[x].sz=size(l)+size(r)+1;
	}
	
	void set(int x, int d, int y){ns[x].ch[d]=y;ns[y].p=x;pull(x);}
	void splay(int x){ 
		auto dir=[&](int x){
			int p=ns[x].p;if(!p)return -1;
			return ns[p].ch[0]==x?0:ns[p].ch[1]==x?1:-1;
		};
		auto rotate=[&](int x){
			int y=ns[x].p,z=ns[y].p,dx=dir(x),dy=dir(y);
			set(y,dx,ns[x].ch[!dx]); 
			set(x,!dx,y);
			if(~dy)set(z,dy,x); 
			ns[x].p=z;
		};
		for(push(x);~dir(x);){
			int y=ns[x].p, z=ns[y].p;
			push(z);push(y);push(x);
			int dx=dir(x),dy=dir(y);
			if(~dy)rotate(dx!=dy?x:y);
			rotate(x);
		}
	}
};
 
struct LinkCut:SplayTree{ // 1-indexed 
	LinkCut(int n):SplayTree(n){}

	int root(int u){
		access(u);splay(u);push(u);
		while(ns[u].ch[0]){u=ns[u].ch[0];push(u);}
		return splay(u),u;
	}

	int parent(int u){
		access(u);splay(u);push(u);
		u=ns[u].ch[0];push(u);
		while(ns[u].ch[1]){u=ns[u].ch[1];push(u);}
		return splay(u),u;
	}

	int access(int x){
		int u=x,v=0;
		for(;u;v=u,u=ns[u].p){
			splay(u); 
			int& ov=ns[u].ch[1];
			// ns[u].vir+=ns[ov].sub;
			// ns[u].vir-=ns[v].sub;
			ov=v;pull(u);
		}
		return splay(x),v;
	}

	void reroot(int x){ 
		access(x);ns[x].flip^=1;push(x); 
	}
	
	void link(int u, int v){ // u->v
		reroot(u);
		access(v); 
		// ns[v].vir+=ns[u].sub;
		ns[u].p=v;pull(v);
	}
	
	void cut(int u, int v){
		int r=root(u);
		reroot(u);
		access(v);
		ns[v].ch[0]=ns[u].p=0;pull(v);
		reroot(r);
	}

	void cut(int u){ // cut parent
		access(u);
		ns[ns[u].ch[0]].p=0;
		ns[u].ch[0]=0;pull(u);
	}
	
	int lca(int u, int v){ 
		if(root(u)!=root(v))return -1;
		access(u);return access(v);
	}

	int depth(int u){
		access(u);splay(u);push(u);
		return ns[u].sz;
	}
	
	// subtree of u, v father
	// T subtree(int u, int v){
	// 	reroot(v);access(u);
	// 	return ns[u].vir+ns[u].self;
	// }

	T path(int u, int v){
		int r=root(u);
		reroot(u);access(v);pull(v);
		T ans=ns[v].path;
		return reroot(r),ans;
	}
	
	void set(int u, T val){
		access(u);
		ns[u].val=val;
		pull(u);
	}

	void upd(int u, int v, T val){
		int r=root(u);
		reroot(u);access(v);splay(v);
		// lazy
		reroot(r);
	}
};
