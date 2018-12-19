#include <iostream>
#include <vector>
using namespace std;
vector<int> v,a;
int n, isMin = 1, isMax = 1;
void dfs(int s){
	if(s * 2 > n && s * 2 + 1 > n){
		if(s <= n){
		for(int i = 0; i < v.size(); i++){
			if(i != 0) cout << " ";
			cout << a[v[i]];
		}
		cout << endl;
		}
		return;
	}
	v.push_back(2*s+1);
	dfs(2*s+1);
	v.pop_back();
	v.push_back(2*s);
	dfs(2*s);
	v.pop_back();
}
int main() 
{
	cin >> n;
	a.resize(n+1);
	for(int i = 1; i <=n; i++){
		cin >> a[i];
	}
 	for(int i = 2; i <= n; i++) {
		if (a[i/2] > a[i]) isMin = 0;
		if (a[i/2] < a[i]) isMax = 0;
	}
	v.push_back(1);
	dfs(1);
	if (isMin == 1)
		printf("Min Heap");
	else 
		printf("%s", isMax == 1 ? "Max Heap" : "Not Heap"); 
	return 0;
}