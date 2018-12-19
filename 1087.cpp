#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
map<string, int> n2id;
map<int, string> id2n;
int g[210][210];
bool vis[210];
int dis[210];
int weight[210];
int w[210];
int num[210];
int n, k, d;
const int inf = 99999999;
vector<vector<int> > pre;
vector<int> ans;
//void p(int i){
//	if(pre[i] == -1) return;
//	else{
//		ans.push_back(i);
//		p(pre[i]);
//	}
//}
vector<int> temppath, path;
int optvalue = -1;
int cntpath = 0;
float avaopt;
void dfs(int v){
	if(v == 0){
		temppath.push_back(v);
		int value = 0;
		
		for(int i = temppath.size()-1; i >=0; i--) value += weight[temppath[i]];
		if(value > optvalue){
			optvalue = value;
			avaopt = optvalue * 1.0 / (temppath.size()-1);
			path = temppath;
		}else if(value == optvalue){
			if(value * 1.0 /(temppath.size()-1) > avaopt){
				avaopt = optvalue * 1.0 / (temppath.size()-1) ;
				path = temppath;
			}
		}
		cntpath++;
		temppath.pop_back();
		return;
	}
	temppath.push_back(v);
	for(int i = 0; i < pre[v].size(); i++){
		dfs(pre[v][i]);
	}
	temppath.pop_back();
}
int main() 
{
	string s1;
	cin >> n >> k >> s1;
	n2id[s1] = 0;
	id2n[0] = s1;
	for(int i = 1; i < n; i++){
		string temp;
		int tint;
		cin >> temp >> tint;
		n2id[temp] = i;
		id2n[i] = temp;
		weight[i] = tint;
	}
	pre.resize(n);

	int s = n2id[s1];
	for(int i = 0; i < k; i++){
		string s2, s3;
		int temp;
		cin >> s2 >> s3 >> temp;
		int a = n2id[s2];
		int b = n2id[s3];
		g[a][b] = g[b][a] = temp;
	}
	fill(dis, dis + n, inf);
	fill(w, w + n, inf);
	dis[s] = 0;
	w[s] = 0;
	num[s] = 1;
	for(int i = 0; i < n; i++){
		int v = -1, minn = inf;
		for(int j = 0; j < n; j++){
			if(vis[j] == false && dis[j] < minn){
				v = j;
				minn = dis[j];
			}
		}
		if(v == -1) break;
		vis[v] = true;
		for(int u = 0; u < n; u++){
			if(vis[u] == false && g[v][u] != 0){
				if(dis[u] > dis[v] + g[v][u]){
					dis[u] = dis[v] + g[v][u];
					w[u] = w[v] + weight[v];
					pre[u].clear();
					pre[u].push_back(v);

				}else if(dis[u] == dis[v] + g[v][u]){
					
						pre[u].push_back(v);
					

				}
				
			}
		}
	}
	d = n2id["ROM"];
	dfs(d);
	cout << cntpath<<" "<<dis[d]<<" "<<optvalue<<" "<<(optvalue)/(path.size()-1);
	cout << endl;
	for(int i = path.size() - 1; i >= 0; i--){
		if(i != path.size() - 1) cout << "->";
		cout << id2n[path[i]];
	}
//	}
//	cout << id2n[0];
//	for(int i = ans.size() -1; i >= 0; i--)
//		cout << "->" << id2n[ans[i]];
	return 0;
}