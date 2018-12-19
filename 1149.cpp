#include <iostream>
#include <vector>
#include <map>
using namespace std;
int n, m, k;
map<int, vector<int> > a;

int main() 
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		int s1, s2;
		scanf("%d%d", &s1, &s2);
		a[s1].push_back(s2);
		a[s2].push_back(s1);
	}
	for(int i = 0; i < m; i++) {
		int flag = 1;
		scanf("%d", &k);
		map<int, int> b;
		map<int, int> e;
		for(int j = 0; j < k; j++){
			int s3;
			scanf("%d", &s3);
			if(b[s3] == 1){
				flag = 0;
			}
			e[s3] = 1;
			if(!a[s3].empty()){
				for(auto i = a[s3].begin(); i != a[s3].end(); i++){
					if(e[*i]==1){
						flag = 0;
					}
					b[*i] = 1;
				}
			}
		}
		if(flag == 1) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}