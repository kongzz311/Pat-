#include <iostream>
#include <vector>
using namespace std;
int g[210][210], n, m, k, l;
int main() 
{
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		g[a][b] = g[b][a] = 1;
	}
	cin >> k;
	for(int i = 0; i < k; i++){
		cin >> l;
		int flag = 1, pre, now, start;
		int c[210] = {0};
		cin >> pre;
		start = pre;
		c[pre] = 1;
		if(l!=n+1) flag = 0;
		for(int j = 1; j < l; j++){
			cin >> now;
			if(j == l-1 && now!=start){
				flag = 0;

			}
			if(g[pre][now] != 1){
				flag = 0;
	
			}
			c[now] += 1;
			pre = now;
		}
		for(int i = 1; i <= n; i++){
		  if(c[i]!= 1){
		    if(i!=start)
		      flag = 0;
		  }
		  if(c[i] > 2) flag = 0;
		}
	  
		if(flag == 1) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}