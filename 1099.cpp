#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct Node{
	int data;
	int r, l;
}node[110];
vector<int> input;
vector<int> seq;
vector<int> ans;
int n;
void in(int s){
	if(s == -1) return;
	in(node[s].l);
	seq.push_back(s);
	in(node[s].r);
}
void level(int s){
	if(s == -1) return;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		ans.push_back(node[temp].data);
		if(node[temp].l != -1) q.push(node[temp].l);
		if(node[temp].r != -1) q.push(node[temp].r);
	}
}
bool cmp1(int a, int b){
	return a < b;
}
int main() 
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int l, r;
		scanf("%d%d", &l, &r);
		node[i].l = l;
		node[i].r = r;
	}
	for(int i = 0; i < n; i++){
		int temp;
		scanf("%d", &temp);
		input.push_back(temp);
	}
	sort(input.begin(), input.end(), cmp1);
	in(0);
	for(int i = 0; i < n; i++){
		node[seq[i]].data = input[i]; 
	}
	level(0);
	for(int i = 0; i < n; i++){
		if(i!=0) printf(" ");
		printf("%d", ans[i]);
//		printf("\n"); 
//		printf("%d", node[i].data);
	}
	return 0;
}