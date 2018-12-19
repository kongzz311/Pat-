#include <iostream>
#include <vector>
using namespace std;
struct node{
	int val;
	node* r, *l;	
};
void create(node*& root, int x){
	if(root == NULL){
		root = new node;
		root -> val = x;
		root -> l = root -> r = NULL;
		return;
	}
	else if(x <= root->val)
		create(root->l, x);
	else
		create(root->r, x);
}
void traverse(node* root, int level, vector<vector<int> > &ans){
	if(root == NULL) return;
	while(level>ans.size()) ans.push_back(vector<int>());
	ans[level-1].push_back(root->val);
	traverse(root->l, level+1, ans);
	traverse(root->r, level+1, ans);
}
vector<vector<int> > level(node* root){
	vector<vector<int> > ans;
	traverse(root, 1, ans);
	return ans;
}
int main() 
{
	int n;
	cin >> n;
	node* root = NULL;
	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		create(root, temp);
	}
	vector<vector<int> > ans =  level(root);
	int lowest = ans.size();
	int a = ans[lowest-1].size();
	int b = ans[lowest-2].size();
	cout << a <<" + "<<b<<" = "<< a+b;
	return 0;
}