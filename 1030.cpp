// 
#include <iostream>

using namespace std;
const int maxv = 505;
const int inf = 99999999;
int g[maxv][maxv], dis[maxv], c[maxv][maxv], pre[maxv], cost[maxv];
int n, m, s, d;
bool vis[maxv] = {false};

void p(int s, int d) {
	if(s == d) {
		cout << d << " ";
		return;
	}
	
	p(s, pre[d]);
	cout << d << " ";
}

int main() 
{
	cin >> n >> m >> s >> d;
	fill(g[0], g[0] + maxv * maxv, inf);
	for (int i = 0; i < m; i++) {
		int a, b, c1, d;
		cin >> a >> b >> c1 >> d;
		g[a][b] = g[b][a] = c1;
		c[a][b] = c[b][a] = d;
	}
	
	
	fill(dis, dis + maxv, inf);
	fill(vis, vis + maxv, false);
	fill(cost, cost + maxv, inf);
	dis[s] = 0;
	for(int i = 0; i < n; i++) pre[i] = i;
	cost[s] = 0; 
	for(int i = 0; i < n; i++) {
		int u = -1, minn = inf;
		for(int j = 0; j < n; j++) {
			if(vis[j] == false && dis[j] < minn) {
				minn = dis[j];
				u = j;
			}
		}
		if(u == -1) break;
		vis[u] = true;
		for(int v = 0; v< n; v++) {
			if(vis[v] == false && g[u][v] != inf) {
				if(dis[v] > dis[u] + g[u][v]) {
					dis[v] = dis[u] + g[u][v];
					pre[v] = u;
					cost[v] = cost[u] + c[u][v];
				}
				else if(dis[v] == dis[u] + g[u][v]) {
					if(cost[v] > cost[u] + c[u][v]) {
						cost[v] = cost[u] + c[u][v];
						pre[v] = u;
					}
				}
			}
		}
	}
	
	p(s, d);
	cout <<dis[d]<<" "<<cost[d];
	
	return 0;
}