// 
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> stringtoint;
map<int, string> inttostring;
map<string, int> ans;

int idNumber = 1, k;
int stoifunc(string s) {
	if(stringtoint[s] == 0) {
		stringtoint[s] = idNumber;
		inttostring[idNumber] = s;
		return idNumber++;
	}else{
		return stringtoint[s];
	}
}

int g[2010][2010],weight[2010];
bool vis[2010];

void dfs(int u, int &head, int &numMember, int &totalweight) {
	vis[u] = true;
	numMember++;
	if(weight[u] > weight[head])
		head = u;
	for(int v = 1; v < idNumber; v++) {
		if(g[u][v] > 0) {
			totalweight += g[u][v];
			g[u][v] = g[v][u] = 0;
			if(vis[v] == false)
				dfs(v, head, numMember, totalweight);
		}
	}
}

void dfsTrave() {
	for(int i = 1; i < idNumber; i++) {
		if(vis[i] == false) {
			int head = i, numMember = 0, totalweight = 0;
			dfs(i, head, numMember, totalweight);
			if(numMember > 2 && totalweight > k)
				ans[inttostring[head]] = numMember;
		}
	}
}


 

int main() 
{
	int n, w;
	cin >> n >> k;
	string s1, s2;
	for(int i = 0; i < n; i++) {
		cin >> s1 >> s2 >> w;
		int id1 = stoifunc(s1);
		int id2 = stoifunc(s2);
		weight[id1] += w;
		weight[id2] += w;
		g[id1][id2] += w;
		g[id2][id1] += w;
	}
		
	dfsTrave();
	cout << ans.size() << endl;
	for(auto it = ans.begin(); it != ans.end(); it++) 
		cout << it->first <<" "<<it->second << endl;
		
	
	return 0;
}