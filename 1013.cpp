// 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, k; //cities, highways, cheaks;

int g[1010][1010];
const int inf = 1000000;

bool vis[1010];

int occupied;

void dfs(int s){
	
	vis[s] = true;
	for(int i = 1; i <= n; i ++) {
		if(g[s][i] != inf && vis[i] == false)
			dfs(i);
	}
}

int main() 
{
	fill(g[0], g[0] + 1010 * 1010, inf);
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a][b] = g[b][a] = 1;
	}
	
	
	
	for(int i = 0; i < k; i++) {
		fill(vis, vis + 1010, false);
		scanf("%d", &occupied);
		vis[occupied] = true;
		int cnt = 0;
		for(int j = 1; j <= n; j++) {
			if(!vis[j])
			{
				dfs(j);
				cnt++;
			}
		}
		
		printf("%d\n", cnt - 1);
		
	}
	
	return 0;
}