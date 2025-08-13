// 1-indexed 
// All operations are O(log(n))
typedef long long T;
struct SplayTree{
	struct Node{
		int ch[2]={0, 0},p=0;
		T val=0,path=0; // values for path
		T sub=0,vir=0; // values for subtree
		bool flip=0; // values for lazy		
	};
	vector<Node> ns;
	SplayTree(int n):ns(n+1){}
	T path(int u){return (u?ns[u].path:0);}
	T subsum(int u){return (u?ns[u].sub:0);}
	void push(int x){
		if(!x)return;
		int l=ns[x].ch[0],r=ns[x].ch[1];
		if(ns[x].flip){
			ns[l].flip^=1,ns[r].flip^=1;
			swap(ns[x].ch[0], ns[x].ch[1]); 
			// if the operation is like a segment tree
			// check swap the values
			ns[x].flip=0;
		}
	}
	void pull(int x){
		int l=ns[x].ch[0],r=ns[x].ch[1];
		push(l);push(r); 
		ns[x].path=max({path(l), path(r), ns[x].val});
		ns[x].sub=ns[x].vir+subsum(l)+subsum(r)+ns[x].val;
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

struct LinkCut:SplayTree{ 
	LinkCut(int n):SplayTree(n){}
	// return the root of us tree
	int root(int u){
		access(u);splay(u);push(u);
		while(ns[u].ch[0]){u=ns[u].ch[0];push(u);}
		return splay(u),u;
	}
	// return the parent of u
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
			ns[u].vir+=ns[ov].sub;
			ns[u].vir-=ns[v].sub;
			ov=v;pull(u);
		}
		return splay(x),v;
	}
	// reroot the tree with x as root
	void reroot(int x){ 
		access(x);ns[x].flip^=1;push(x); 
	}
	// create a edge u->v, u is the child of v
	void link(int u, int v){ 
		reroot(u);access(v); 
		ns[v].vir+=ns[u].sub;
		ns[u].p=v;pull(v);
	}
	// delete the edge u->v, u is the child of v
	void cut(int u, int v){
		int r=root(u);
		reroot(u);access(v);
		ns[v].ch[0]=ns[u].p=0;pull(v);
		reroot(r);
	}
	// delete the edge u->parent(u)
	void cut(int u){ 
		access(u);
		ns[ns[u].ch[0]].p=0;
		ns[u].ch[0]=0;pull(u);
	}
	int lca(int u, int v){ 
		if(root(u)!=root(v))return -1;
		access(u);return access(v);
	}
	// return sum of the subtree of u with v as father
	T subtree(int u, int v){
		int r=root(u);
		reroot(v);access(u);
		T ans=ns[u].vir+ns[u].val; 
		return reroot(r),ans;
	}
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
};
