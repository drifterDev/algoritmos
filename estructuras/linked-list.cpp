#include <bits/stdc++.h>
using namespace std;
typedef long long T;

struct Node{
	T value;
	Node* next;
	Node* prev;

	Node(T v){
		value=v;
		next=prev=nullptr;
	}
};

typedef Node* PNode;
struct Lista{
	PNode head,tail;
	int size;

	Lista(){
		head=tail=nullptr;
		size=0;
	}
	deque<int> dq;
	void push_front(T v){
		PNode tmp=new Node(v);
		tmp->next=head;
		if (head!=nullptr)head->prev=tmp;
		else tail=tmp;
		head=tmp;
		size++;
	}

	void push_back(T v) {
		PNode tmp=new Node(v);
		tmp->prev=tail;
		if(tail!=nullptr)tail->next=tmp;
		else head=tmp; 
		tail=tmp;
		size++;
	}

	void print(){
		PNode tmp=head;
		while(tmp!=nullptr){
			cout<<tmp->value<<" ";
			tmp=tmp->next;
		}
		cout<<"\n";
	}

	void pop(PNode x){
		if(x->prev!=nullptr)x->prev->next=x->next;
		if(x->next!=nullptr)x->next->prev=x->prev;
		delete x;
	}
};
