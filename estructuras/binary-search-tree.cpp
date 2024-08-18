#include <bits/stdc++.h>
using namespace std;
typedef long long T;

struct Node{
	int value;
	struct Node *l, *r;
	Node(T v){
		value=v;
		l=r=nullptr;
	}
};

typedef Node* PNode;
PNode insert(PNode x, T v){
	if(!x)return new Node(v);
	if(v<x->value)x->l=insert(x->l, v);
	else if(v>x->value)x->r=insert(x->r, v);
	return x;
}

PNode search(PNode x, T v){
	if(!x || x->value==v)return x;
	if(x->value<v)return search(x->r, v);
	return search(x->l, v);
}

PNode min(PNode x){
	PNode act=x;
	while(act && act->l!=nullptr)act=act->l;
	return act;
}

PNode remove(PNode x, T v){
	if(!x)return x;
	if(v<x->value)x->l=remove(x->l, v);
	else if(v>x->value)x->r=remove(x->r, v);
	else{
		if(!x->l){
			PNode tmp=x->r;
			free(x);
			return tmp;
		}else if(!x->r){
			PNode tmp=x->l;
			free(x);
			return tmp;
		}
		PNode tmp=min(x->r);
		x->value=tmp->value;
		x->r=remove(x->r, tmp->value);
	}
	return x;
}

void dfs(PNode x){
	if(!x)return;
	dfs(x->l);
	cout<<x->value<<" ";
	dfs(x->r);
}

int main(){
	PNode root=nullptr;
	root=insert(root, 50);
	insert(root, 30);
	insert(root, 100);
	insert(root, 20);
	if(search(root, 60)==nullptr)cout<<"60 not found\n";
	else cout<<"60 found\n";
	PNode mini=min(root);
	cout<<"Minimum value: "<<mini->value<<"\n";
	dfs(root);cout<<"\n";
	root=remove(root, 30);
	dfs(root);cout<<"\n";
	return 0;
}
