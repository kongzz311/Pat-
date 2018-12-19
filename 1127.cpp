#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node{
	int val;
	node* r, *l;	
};
vector<int> in, post, pre;
vector<int>ans[100];
int n;
node* postT(int postL, int postR, int inL, int inR){
	if(postL > postR) return NULL;
	node* root = new node;
	root->val = post[postR];
	int i = inL;
	for(; i <= inR; i++) if(post[postR] == in[i]) break;
	root->l=postT(postL, postL+i-inL-1, inL, i-1);
	root->r=postT(postL+i-inL, postR-1, i+1, inR);
	return root;
}
//void insert(node* &root, int x){
//	if(root == NULL){
//		root = new node;
//		root->val = x;
//		root->l = root -> r = NULL;
//		return;
//	}
//	if(x < root -> val)
//		insert(root->l, x);
//	else
//		insert(root->r, x);
//}

void traverse(node* root, int level, vector<vector<int> > &result, bool left_to_right){
	if(!root) return;
	if(level > result.size()) result.push_back(vector<int>());
	if(left_to_right)
		result[level-1].push_back(root->val);
	else 
		result[level-1].insert(result[level-1].begin(), root->val);
	traverse(root->l, level+1, result, !left_to_right);
	traverse(root->r, level+1, result, !left_to_right);
}
vector<vector<int> > levelTravel(node* root){
	vector<vector<int> > result;
	traverse(root, 1, result, false);
	return result;
}

int main() 
{
	cin >> n;
	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		in.push_back(temp);
	}
	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		post.push_back(temp);
	}
	node* root = postT(0, n-1, 0, n-1);
	
//	for(auto i = pre.begin(); i!= pre.end(); i++)
//		insert(root, *i);
	vector<vector<int> >ans = levelTravel(root);
	int flag = 0;
	for(int i = 0; i != ans.size(); i++){
		for(auto j = ans[i].begin(); j != ans[i].end(); j++)
			if(flag == 0){
				cout << *j;
				flag = 1;
			}
			else cout << " " << *j;
	}
	return 0;
}