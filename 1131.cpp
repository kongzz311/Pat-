#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<vector<int> > v(10000);
int visit[10000], minCnt, minTransfer, s, e;
unordered_map<int, int> line;
vector<int> path, tempPath;
int transferCnt(vector<int> a){
	int cnt = -1, preline = 0;
	for(int i = 1; i < a.size(); i++){
		if(line[a[i-1]*10000+a[i]] != preline) cnt ++;
		preline = line[a[i-1]*10000+a[i]];
	}
	return cnt;
	
}
void dfs(int node, int cnt){
	if(node == e && (cnt < minCnt ||(cnt == minCnt && transferCnt(tempPath) < minTransfer))){
		minCnt = cnt;
		minTransfer = transferCnt(tempPath);
		path = tempPath;
	}
	if(node == e) return;
	for(int i = 0; i < v[node].size(); i++){
		if(visit[v[node][i]] == 0){
			visit[v[node][i]] = 1;
			tempPath.push_back(v[node][i]);
			dfs(v[node][i], cnt+1);
			visit[v[node][i]] = 0;
			tempPath.pop_back();
		}
	}
}
int main(){
	int n, m, k, pre, temp;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d%d", &m, &pre);
		for(int j = 1; j < m; j++){
			scanf("%d", &temp);
			v[pre].push_back(temp);
			v[temp].push_back(pre);
			line[pre*10000+temp] = line[temp*10000+pre] = i+1;
			pre = temp;
		}
	}
	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		scanf("%d%d", &s, &e);
		minCnt = 99999, minTransfer = 99999;
		tempPath.clear();
		tempPath.push_back(s);
		dfs(s, 0);
		visit[s] = 0;
		printf("%d\n", minCnt);
		int preline = 0, preTransfer = s;
		for(int j = 1; j < path.size(); j++){
			if(line[path[j-1]*10000+path[j]]!=preline){
				if (preline != 0) printf("Take Line#%d from %04d to %04d.\n", preline, preTransfer, path[j-1]); 
				preline = line[path[j-1]*10000+path[j]]; 
				preTransfer = path[j-1];
			}
		}
		printf("Take Line#%d from %04d to %04d.\n", preline, preTransfer, e);
	}
	return 0;
}
