// 
#include <iostream>
#include <algorithm>

using namespace std;

int all1[100000];
int cnt[100000];

int main() 
{
	fill(cnt, cnt + 100000, 0);
	int s1, s2, n;
	scanf("%d%d%d", &s1, &s2, &n);
	for(int i = 0; i < n; i++) {
		int a, b;
		char c;
		scanf("%d %c %d", &a, &c, &b);
		all1[a] = b;
	}
	
	int flag = 0, now = s1;
	while(now != -1){

		cnt[now] = 1;
		
		now = all1[now];		
	}
	
	now = s2;
	while(now != -1){

		if(cnt[now] == 1)
		{
			flag = 1;
			break;
		}
		now = all1[now];		
	}
	
	if(flag == 1) printf("%05d", now);
	else cout << -1;
	return 0;
}