#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"
typedef vector<int> vi;

struct Node{
	int key;
	struct Node *left, *right;
};

struct Node* newNode(int item){
	struct Node* temp=new struct Node;
	temp->key=item;
	temp->left=temp->right=NULL;
	return temp;
}

struct Node* insert(struct Node* Node, int key){
	if(Node==NULL)return newNode(key);
	if(key<Node->key)Node->left=insert(Node->left, key);
	else if(key>Node->key)Node->right=insert(Node->right, key);
	return Node;
}

struct Node* search(struct Node* root, int key){
	if(root==NULL || root->key==key)return root;
	if(root->key<key)return search(root->right, key);
	return search(root->left, key);
}

struct Node* minValueNode(struct Node* Node){
	struct Node* current=Node;
	while(current && current->left!=NULL)current=current->left;
	return current;
}

struct Node* deleteNode(struct Node* root, int key){
	if(root==NULL)return root;
	if(key<root->key)root->left=deleteNode(root->left, key);
	else if(key>root->key)root->right=deleteNode(root->right, key);
	else{
		if(root->left==NULL){
			struct Node* temp=root->right;
			free(root);
			return temp;
		}else if(root->right==NULL){
			struct Node* temp=root->left;
			free(root);
			return temp;
		}
		struct Node* temp=minValueNode(root->right);
		root->key=temp->key;
		root->right=deleteNode(root->right, temp->key);
	}
	return root;
}

void inorder(vi& order, struct Node* root){
	if(root!=NULL){
		order.push_back(root->key);
		inorder(order, root->left);
		inorder(order, root->right);
	}
}

int main(){
	struct Node* root=NULL;
	root=insert(root, 50);
	insert(root, 30);
	
	if(search(root, 60)==NULL)cout<<"60 not found\n";
	else cout<<"60 found\n";

	struct Node* min=minValueNode(root);
	cout<<"Minimum value: "<<min->key<<"\n";

	vi order;
	inorder(order, root);
	print(order);

	root=deleteNode(root, 30);
	return 0;
}
