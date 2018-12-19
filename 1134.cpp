#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<vector<int> > g;

int main() 
{
	int n, m, k;
	cin >> n >> m;
	g.resize(m);
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		g[i].push_back(a);
		g[i].push_back(b);
	}
	cin >> k;
	for(int i = 0; i < k; i++){
		int nv, flag = 1;
		cin >> nv;
		int ans = 0;
		set<int> s;
		for(int j = 0; j < nv; j++){
			int temp;
			cin >> temp;
			s.insert(temp);
		}
		for(int i = 0; i < m; i++){
			int a = g[i][0], b = g[i][1];
			if(s.find(a) == s.end() && s.find(b) == s.end()) flag = 0;
		}
		if(flag) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}