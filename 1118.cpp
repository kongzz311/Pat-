#include <iostream>
#include <vector>
using namespace std;
int father[10010];
int n, k, m;
int find(int x){
	if(x==father[x]) return x;
	else return find(father[x]);
}
void Union(int a, int b){
	int fa = find(a);
	int fb = find(b);
	if(fa > fb)
		father[fa] = fb;
	else if(fa < fb)
		father[fb] = fa;
}
vector<int> cache;
bool visited[10010];
bool visitedT[10010];
int main() 
{
	scanf("%d", &n);
	for(int i = 1; i < 10010; i++) father[i] = i;
	for(int i = 0; i < n; i++){
		scanf("%d", &k);
		int temp1, temp2;
		scanf("%d", &temp1);
		visited[temp1] = true;
		for(int j = 1; j < k; j++){
			scanf("%d", &temp2);
			visited[temp2] = true;
			Union(find(temp1), find(temp2));
			temp1 = temp2;
		}
		cache.push_back(temp1);
	}
	int cntB = 0;
	for(int i = 0; i < 10010; i++){
		if(visited[i]==true) cntB++;
	}
	int cntT = 0;
	for(int i = 0; i < cache.size(); i++){
		int ind = find(cache[i]);
		if(visitedT[ind] == false){
			cntT++;
			visitedT[ind] = true;
		}
	}
	printf("%d %d\n", cntT, cntB);
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		if(find(a)==find(b))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}