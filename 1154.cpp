#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<vector<int> >g;
int main() 
{
	int n, m;
	cin >> n >> m;
	g.resize(n);
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int k;
	cin >> k;
	for(int i = 0; i < k; i++){
		vector<int> c(n);
		int flag = 1;
		for(int j = 0; j < n; j++)
			cin >> c[j];
		for(int j = 0; j < n; j++){
			int nowc = c[j];
			for(int k = 0; k < g[j].size(); k++){
				if(nowc == c[g[j][k]])
					flag = 0;
			}
		}
		if(flag == 0) cout << "No\n";
		else {
			int cnt = 0;
			map<int, int> colcnt;
			for(int j = 0; j < n; j++){
				if(colcnt[c[j]] == 0){
					colcnt[c[j]] = 1;
					cnt++;
				}
			}
			cout << cnt <<"-coloring\n";
		}
	}
	return 0;
}