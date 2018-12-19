// 
#include <iostream>

using namespace std;

struct node{
	int data;
	int layer;
	node* r, l;	
};

//
node* build(int d) {
	node* temp = new node;
	temp.data = d;
	temp.r = temp.l = NULL;
	return temp;
}

// search with edit
void search(node* root, int x, int newdata) {
	if(root == NULL)
		return;
	if(root -> data == x)
		root -> data = newdata;
	search(root -> l, x, newdata);
	search(root -> r, x, newdata);
}

// insert &root !!!!!
void insert(node* &root, int x) {
	if(root == NULL){
		root = build(x);
		return;
	}
	if(x < root -> data)
		insert(root -> l, x);
	else
		insert(root -> r, x);
}

node* Create(int data[], int n) {
	node* root = NULL;
	for(int i = 0; i < n; i++) {
		insert(root, data[i]);
	}
	return root;
}

void preorder(node* root) {
	if(root == NULL)
		return;
	cout << root -> data;
	preorder(root -> l);
	preorder(root -> r);
}

void inorder(node* root) {
	if(root == NULL)
		return;
	inorder(root -> l);
	cout << root -> data;
	inorder(root -> r)
}

void postorder(node* root) {
	if(root == NULL)
		return;
	postorder(root -> l);
	postorder(root -> r);
	cout << root -> data;
}

void layerOrder(node* root){
	queue<node*> q;
	root -> layer = 1;
	q.push(root);
	while(!q.empty()){
		node* now = q.front;
		q.pop();
		cout << now -> data;
		if(now -> l != NULL) 
		{	
			q.push(now -> l);
			now -> l -> layer = now -> layer + 1;
		}
		if(now -> r != NULL) 
		{
			q.push(now -> r);
			now -> r -> layer = now -> layer + 1;
		}
	}
}

node* create(int preL, int preR, int inL, int inR) {
	if(preL > preR) return;
	node * root = new node;
	root -> data = pre[preL];
	int k;
	for(k = inL; k <= inR; k++) {
		if(in[k] == pre[preL])
			break;
	}
	int numLeft = k - inL;
	
	root -> l = create(preL+1, preL + numLeft, inL, k - 1);
	root -> r = create(preL+numLeft+1, preR, k+1, inR);
	
	return root;
}

int main() 
{
	
	return 0;
}