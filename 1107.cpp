#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int father[1010];
bool visited[1010];
int find(int x){
	if(x == father[x]) return x;
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
vector<int> ans(1010);
bool cmp1(int a, int b){
	return a > b;
}
int main() 
{
	int n, k;
	scanf("%d", &n);
	for(int i = 1; i < 1010; i++){
		father[i] = i;
	}
	for(int i = 1; i <= n; i++){
		scanf("%d:", &k);
		int temp1, temp2;
		scanf("%d", &temp1);
		visited[temp1] = true;
		for(int j = 1; j < k; j++){
			scanf("%d", &temp2);;
			visited[temp2] = true;
			Union(find(temp1), find(temp2));
			temp1 = temp2;
		}
		cache.push_back(temp1);
	}
	int temp = find(cache[0]);
	for(int i = 0; i < n; i++){
		int ind = find(cache[i]);
		ans[ind]++;
	}
	sort(ans.begin(), ans.end(), cmp1);
	int cnt = 0;
	for(; cnt < 1010; cnt++) if(ans[cnt] == 0) break;
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; i++){
		if(i == 0)
			printf("%d", ans[i]);
		else
			printf(" %d", ans[i]);
	}
	return 0;
}