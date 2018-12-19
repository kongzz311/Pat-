// 
#include <iostream>
#include <vector>
using namespace std;
struct node{
	int data;
	node *r, *l;
};
void insert(node* &root, int data){
	if(root == NULL){
		root = new node;
		root -> data = data;
		root -> l = root -> r = NULL;
		return;
	} 
	if(data < root -> data) insert(root -> l, data);
	else insert(root -> r, data);
}
void preOrder(node* root, vector<int>&vi){
	if(root == NULL) return;
	vi.push_back(root -> data);
	preOrder(root -> l, vi);
	preOrder(root -> r, vi);
}
void preOrderM(node* root, vector<int>&vi){
	if(root == NULL) return;
	vi.push_back(root -> data);
	preOrderM(root -> r, vi);
	preOrderM(root -> l, vi);
}
void postOrder(node* root, vector<int>&vi){
	if(root == NULL) return;
	postOrder(root -> l, vi);
	postOrder(root -> r, vi);
	vi.push_back(root -> data);
}
void postOrderM(node* root, vector<int>&vi){
	if(root == NULL) return;
	postOrderM(root -> r, vi);
	postOrderM(root -> l, vi);
	vi.push_back(root -> data);
}
vector<int> origin, pre, preM, post, postM;
int main() 
{
	int n, data;
	node* root = NULL;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &data);
		origin.push_back(data);
		insert(root, data);
	}
	preOrder(root, pre);
	preOrderM(root, preM);
	postOrder(root, post);
	postOrderM(root, postM);
	if(origin == pre){
		printf("YES\n");
		for(int i = 0; i < post.size(); i++) {
			printf("%d", post[i]);
			if(i<post.size()-1) printf(" ");
		}
	}else if(origin == preM){
		printf("YES\n");
		for(int i = 0; i < postM.size(); i++) {
			printf("%d", postM[i]);
			if(i<postM.size()-1) printf(" ");
		}
	}else {
		printf("NO\n");
	}
	return 0;
}