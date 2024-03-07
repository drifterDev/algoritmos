// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"
typedef vector<int> vi;

struct node{
	int key;
	struct node *left, *right;
};

struct node* newNode(int item){
	struct node* temp=new struct node;
	temp->key=item;
	temp->left=temp->right=NULL;
	return temp;
}

struct node* insert(struct node* node, int key){
	if(node==NULL)return newNode(key);
	if(key<node->key)node->left=insert(node->left, key);
	else if(key>node->key)node->right=insert(node->right, key);
	return node;
}

struct node* search(struct node* root, int key){
	if(root==NULL || root->key==key)return root;
	if(root->key<key)return search(root->right, key);
	return search(root->left, key);
}

struct node* minValueNode(struct node* node){
	struct node* current=node;
	while(current && current->left!=NULL)current=current->left;
	return current;
}

struct node* deleteNode(struct node* root, int key){
	if(root==NULL)return root;
	if(key<root->key)root->left=deleteNode(root->left, key);
	else if(key>root->key)root->right=deleteNode(root->right, key);
	else{
		if(root->left==NULL){
			struct node* temp=root->right;
			free(root);
			return temp;
		}else if(root->right==NULL){
			struct node* temp=root->left;
			free(root);
			return temp;
		}
		struct node* temp=minValueNode(root->right);
		root->key=temp->key;
		root->right=deleteNode(root->right, temp->key);
	}
	return root;
}

void inorder(vi& order, struct node* root){
	if(root!=NULL){
		order.push_back(root->key);
		inorder(order, root->left);
		inorder(order, root->right);
	}
}

int main(){
	struct node* root=NULL;
	root=insert(root, 50);
	insert(root, 30);
	
	if(search(root, 60)==NULL)cout<<"60 not found\n";
	else cout<<"60 found\n";

	struct node* min=minValueNode(root);
	cout<<"Minimum value: "<<min->key<<"\n";

	vi order;
	inorder(order, root);
	print(order);

	root=deleteNode(root, 30);
	return 0;
}
