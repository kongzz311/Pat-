#include <iostream>
#include <vector>
using namespace std;
struct node{
	string data;
	int l = -1, r = -1;
	int height = 0;
};
vector<node> t;
int update(int i){
	if(i == -1) return 0;
	else return max(update(t[i].l), update(t[i].r))+ 1;
}
vector<string> ans;
void inorder(int root){
	if(t[root].l != -1||t[root].r != -1) ans.push_back("(");
	if(t[root].l != -1) inorder(t[root].l);
	ans.push_back( t[root].data);
	if(t[root].r != -1)inorder(t[root].r);
	if(t[root].l != -1||t[root].r != -1) ans.push_back(")");
	
}
int main() 
{
	int n;
	cin >> n;
	t.resize(n+1);
	for(int i = 1; i <= n; i++){
		string s;
		int l, r;
		cin >> s >> l >> r;
		t[i].data = s;
		t[i].l = l;
		t[i].r = r;
	}
	int maxheight = -1, root;
	for (int i = 1; i <= n; i++) {
		t[i].height = update(i);
		if(t[i].height > maxheight){
			maxheight = t[i].height;
			root = i;
		}
	}
	inorder(root);
	if(*ans.begin() == "(")ans.erase(ans.begin());
	if(ans.size() > 0 && *(ans.end()-1) == ")") ans.erase(ans.end() - 1);
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i];
	return 0;
}