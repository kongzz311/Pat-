// avl
#include <iostream>
#include <algorithm>

using namespace std;

struct node{
	int data, height;
	node* r, *l;
};

node* create(int x){
	node* Node = new node;
	Node -> data = x;
	Node -> height = 1;
	Node -> r = Node -> l = NULL;
	return Node;
}

int getHeight(node*& root){
	if(root == NULL) return 0;
	return root -> height;
}

int getBalanceFactor(node* root){
	return getHeight(root -> l) -getHeight(root -> r);
}

void updateHeight(node* root){
	root -> height = max(getHeight(root -> l), getHeight(root -> r)) +1;
}




void deleteNode(node* &root, int x) {
	if(root == NULL) return;
	if(root -> data == x){
		if(root -> l == NULL && root -> r == NULL) {
			root = NULL;
		}else if(root -> l != NULL) {
			node *pre = findMax(root -> lchild);
			root -> data = pre-> data;
			deleteNode(pre->l, pre->data);
		}else {
			node *next = findMin(root -> r);
			root -> data = next -> data;
			deleteNode(next -> r, next -> data);
		}
	}else if(root -> data > x){
		deleteNode(root -> l, x);
	}else {
		deleteNode(root -> r, x);
	}
}

void search(node* root, int x){
	if(root == NULL){
		printf("Search failed\n");
		return;
	}
	if(x == root -> data){
		printf("%d", root -> data);
	}else if(x < root -> data){
		search(root -> l, x);
	}else{
		search(root -> r, x);
	}
}

int main() 
{
	
	return 0;
}