#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> > g;
vector<int> ans;
vector<bool> vis;
void dfs(int s){
	vis[s] = true;
	for(int i = 0; i < g[s].size(); i++){
		if(vis[g[s][i]] == false)
			dfs(g[s][i]);
	}
}
int main() 
{
	int n, m;
	cin >> n >> m;
	g.resize(n+1);
	ans.resize(n+1);
	vis.resize(n+1);
	fill(vis.begin(), vis.end(), false);
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int odd = 0, even = 0, flag = 1, cnt = 0;
	for(int i = 1; i <= n; i++){
		ans[i] = g[i].size();
	}
	for(int i = 1; i <= n; i++){
		if(i!=1) cout << " ";
		cout << ans[i];
	  	if(ans[i]%2==0) even++;
		else if(ans[i]%2==1)odd++;
	}
	cout << endl;
	dfs(1);
	for(int i = 1; i <= n; i++) if(vis[i]==true)cnt++;
	if(cnt != n){
		cout << "Non-Eulerian";
		return 0;
	}
	if(even == n) cout << "Eulerian";
	else if(odd == 2) cout << "Semi-Eulerian";
	else cout << "Non-Eulerian";
	return 0;
}