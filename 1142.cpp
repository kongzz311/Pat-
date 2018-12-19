#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int g[210][210];
int main() 
{
	fill(g[0], g[0]+210*210, 0);
	int nv, ne, m, k;
	cin >> nv >> ne;
	for(int i = 0; i < ne; i++) {
		int a, b;
		cin >> a >> b;
		g[a][b] = g[b][a] = 1;
	}
	for(int i = 1; i <= nv; i++) g[i][i] = 1;
	cin >> m;
	for(int i = 0; i < m; i++) {
		int flag = 1;
		cin >> k;
		vector<int> ans;
		map<int, bool> in;
		int cnt[210];
		fill(cnt, cnt+210, 0);
		for(int j = 0; j < k; j++) {
			int temp;
			cin >> temp;
			in[temp] = true;
			ans.push_back(temp);
		}
		for(auto k = ans.begin(); k != ans.end(); k++) {
			for(int a = 1; a <= nv; a++) {
				if(g[*k][a]==0 && in[a]==true) flag = 3;
				if(g[*k][a]==1 && in[a]==false) cnt[a]++;
			}
		}
		for(int j = 0; j < 210; j++) {
			if(cnt[j]==k){
				flag = 2;
				break;
			}
		}
		if(flag == 3) cout << "Not a Clique\n";
		else if(flag == 2) cout << "Not Maximal\n";
		else cout << "Yes\n";
	}
	return 0;
}