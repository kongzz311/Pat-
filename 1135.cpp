#include <iostream>
#include <algorithm>
using namespace std;
struct node{
	int data;
	node* r, *l;	
};
int n, m, x;
void insert(node* &root, int x){
	if(root == NULL){
		root = new node;
		root -> data = x;
		root -> l = root -> r = NULL;
	}
	else if(abs(x) <= abs(root->data))
		insert(root->l, x);
	else insert(root->r, x);
}
bool judge1(node* root){
	if(root == NULL) return true;
	if(root -> data < 0){
		if(root -> l != NULL && root -> l -> data < 0) return false;
		if(root -> r != NULL && root -> r -> data < 0) return false;
	}
	return judge1(root -> l) && judge1(root -> r);
}
int Ucnt = 0,flag = 1;
void Utravel(node* root){
	if(root == NULL)
		return;
	if(root -> data > 0)
		Ucnt++;
	Utravel(root->r);
}
void travel(node* root, int cnt){
	if(root == NULL){
		if(cnt != Ucnt)  flag = 0;
		return;
	}
	if(root -> data > 0){
		travel(root->l, cnt+1);
		travel(root->r, cnt+1);
	}
	else {
		travel(root->l, cnt);
		travel(root->r, cnt);
	}
}
//int getNum(node* root) {
//	if(root == NULL) return 0;
//	int l = getNum(root -> l);
//	int r = getNum(root -> r);
//	return root -> data > 0 ? max(l, r) + 1 : max(l, r);
//}
//bool judge2(node *root){
//	if(root == NULL) return true;
//	int l = getNum(root->l);
//	int r = getNum(root->r);
//	if(l != r) return false;
//	return judge2(root->l) && judge2(root->r);
//}
int main() 
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &m);
		node* root = NULL;
		flag = 1;
		for(int j = 0; j < m; j++){
			scanf("%d", &x);
			insert(root, x);
			if(j == 0 && x < 0){
				flag = 0;
			}
		}
		Ucnt = 0;
		Utravel(root);
		travel(root, 0);
		if(flag&&judge1(root)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}