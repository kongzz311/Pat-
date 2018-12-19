#include <iostream>
#include <queue>
using namespace std;
struct node{
	int l, r;
}a[11];
vector<int> ans1, ans2;
void bfs(int root){
	if(root == -1) return;
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int temp = q.front();
		ans1.push_back(temp);
		q.pop();
		if(a[temp].r != -1) q.push(a[temp].r);
		if(a[temp].l != -1) q.push(a[temp].l);
		swap(a[temp].r, a[temp].l);
	}
}
void inorder(int root){
	if(root == -1) return;
	inorder(a[root].l);
	ans2.push_back(root);
	inorder(a[root].r);
}
int main() 
{
	int have[11] = {0};
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		string l, r;
		cin >> l >> r;
		if(l == "-"){
			a[i].l = -1;
		}else {
			a[i].l = stoi(l);
			have[stoi(l)] = 1;
		}
		if(r == "-"){
			a[i].r = -1;
		}else {
			a[i].r = stoi(r);
			have[stoi(r)] = 1;
		}
	}
	int root = 0;
	while(have[root]!=0) root++;
	bfs(root);
	for(int i = 0; i < ans1.size(); i++){
		if(i!=0) cout << " ";
		cout << ans1[i];
	}
	cout << endl;
	inorder(root);
	for(int i = 0; i < ans2.size(); i++){
		if(i!=0) cout << " ";
		cout << ans2[i];
	}
	return 0;
}