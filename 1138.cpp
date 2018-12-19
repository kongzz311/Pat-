#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> pre, in, post;
void postC(int preL, int preR, int inL, int inR){
	if(preL > preR) return;
	int temp = pre[preL];
	int i;
	for(i = inL; i <= inR; i++) if(temp == in[i]) break;
	postC(preL+1, preL + i - inL, inL, i-1);
	postC(preL + i - inL + 1, preR, i+1, inR);
	post.push_back(temp);
}
int main() 
{
	scanf("%d", &n);
	pre.resize(n);
	in.resize(n);
	for(int i = 0; i < n; i++) scanf("%d", &pre[i]);
	for(int i = 0; i < n; i++) scanf("%d", &in[i]);
	postC(0, n-1, 0, n-1);
	printf("%d", post[0]);
	return 0;
}