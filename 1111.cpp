#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, s, d;
int g[510][510];
int t[510][510];
vector<int>preLL[510];
vector<int>preTT[510];
bool visited[510];
int dis[510];
const int inf = 99999999;
vector<int> timeans, lengthans;
void length(int s){
	fill(dis, dis+510, inf);
	fill(visited, visited+510, false);
	dis[s] = 0;
	for(int i = 0; i < n; i++){
		int minn = inf, u = -1;
		for(int j = 0; j < n; j++){
			if(visited[j]== false && dis[j] < minn){
				minn = dis[j];
				u = j;
			}
		}
		if(u == -1) break;
		visited[u] = true;
		for(int v = 0; v < n; v++){
			if(visited[v]==false && g[u][v]!=0){
				if(dis[u]+g[u][v]<dis[v]){
					preLL[v].clear();
					dis[v]=dis[u]+g[u][v];
					preLL[v].push_back(u);
				}
				else if(dis[u]+g[u][v]==dis[v]){
					preLL[v].push_back(u);
				}
			}
		}
	}
}
void time(int s){
	fill(dis, dis+510, inf);
	fill(visited, visited+510, false);
	dis[s] = 0;
	for(int i = 0; i < n; i++){
		int minn = inf, u = -1;
		for(int j = 0; j < n; j++){
			if(visited[j]== false && dis[j] < minn){
				minn = dis[j];
				u = j;
			}
		}
		if(u == -1) break;
		visited[u] = true;
		for(int v = 0; v < n; v++){
			if(visited[v]==false && t[u][v]!=0){
				if(dis[u]+t[u][v]<dis[v]){
					preTT[v].clear();
					dis[v]=dis[u]+t[u][v];
					preTT[v].push_back(u);
				}else if(dis[u]+t[u][v]==dis[v]){
					preTT[v].push_back(u);
				}
			}
		}
	}
}
int opttime = inf;
vector<int> temppath, path;
void dfs(int v){
	if(v==s){
		temppath.push_back(v);
		int value = 0;
		for(int i = temppath.size()-1; i > 0; i--){
			int id = temppath[i], idnext = temppath[i-1];
			value += t[id][idnext];
		}
		if(value < opttime){
			opttime = value;
			path = temppath;
		}
		temppath.pop_back();
		return;
	}
	temppath.push_back(v);
	for(int i = 0; i < preLL[v].size(); i++){
		dfs(preLL[v][i]);
	}
	temppath.pop_back();
}
int optpath = inf;
vector<int> temppath2, path2;
void dfs2(int v){
	if(v==s){
		temppath2.push_back(v);
		int value = 0;
		value = temppath2.size();
		if(value < optpath){
			optpath = value;
			path2 = temppath2;
		}
		temppath2.pop_back();
		return;
	}
	temppath2.push_back(v);
	for(int i = 0; i < preTT[v].size(); i++){
		dfs2(preTT[v][i]);
	}
	temppath2.pop_back();
}
//
//void path(int d){
//	lengthans.push_back(d);
//	if(preL[d] == -1) return;
//	path(preL[d]);
//}
//void pathii(int d){
//	timeans.push_back(d);
//	if(preT[d] == -1) return;
//	pathii(preT[d]);
//}
int main() 
{
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		if(c == 1){
			g[a][b]=d;
			t[a][b]=e;
		}else {
			g[a][b] = g[b][a] = d;
			t[a][b] = t[b][a] = e;
		}
	}
	cin >> s >> d;
//	preL[s] = -1;
//	preT[s] = -1;
	length(s);
	int minL = dis[d];
	dfs(d);
//	path(d);
	time(s);
	int minT = dis[d];
	dfs2(d);
//	pathii(d);
	if(path2==path){
		printf("Distance = %d; Time = %d: ", minL, minT);
		for(auto i = path.rbegin(); i!= path.rend(); i++){
			if(i==path.rbegin())
				printf("%d", *i);
			else
				printf(" -> %d", *i);
		}
	}
	else {
		printf("Distance = %d: ", minL);
		for(auto i = path.rbegin(); i!= path.rend(); i++){
			if(i==path.rbegin())
				printf("%d", *i);
			else
				printf(" -> %d", *i);
		}
		printf("\n");
		printf("Time = %d: ", minT);
		for(auto i = path2.rbegin(); i!= path2.rend(); i++){
			if(i==path2.rbegin())
				printf("%d", *i);
			else
				printf(" -> %d", *i);
		}
	}
	return 0;
}