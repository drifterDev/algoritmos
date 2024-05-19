#include <bits/stdc++.h>
using namespace std;

struct Node{
	int value;
	Node* next;
	Node* prev;
};

struct Lista{
	Node* head;
	Node* tail;
	int size;
};

Lista* constructor(){
	Lista* lista=new Lista;
	lista->head=nullptr;
	lista->tail=nullptr;
	lista->size=0;
	return lista;
}

void insertBegin(Lista* lista, int value){
	Node* tmp=new Node;
	tmp->value=value;
	tmp->prev=nullptr;
	tmp->next=lista->head;
	if (lista->head!=nullptr)lista->head->prev=tmp;
	else lista->tail=tmp;
	lista->head=tmp;
	lista->size++;
}

void insertEnd(Lista* lista, int value) {
	Node* tmp=new Node;
	tmp->value=value;
	tmp->next=nullptr;
	tmp->prev=lista->tail;
	if(lista->tail!=nullptr)lista->tail->next=tmp;
	else lista->head=tmp; 
	lista->tail=tmp;
	lista->size++;
}

void imprimir(Lista* lista){
	Node* temp=lista->head;
	while(temp!=nullptr){
		cout<<temp->value<<" ";
		temp=temp->next;
	}
	cout<<"\n";
}

void deleteNode(Node* node){
	if(node->prev!=nullptr)node->prev->next=node->next;
	if(node->next!=nullptr)node->next->prev=node->prev;
	delete node;
}
