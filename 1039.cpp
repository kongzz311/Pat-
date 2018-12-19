//// 
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <map>
//using namespace std;
//
//
//map<string, vector<int> > q;
//
//
//int main() 
//{
//	int n, k, course, s;
//	string name;
//	cin >> n >> k;
//	for(int i = 0; i < k; i++) {
//		cin >> course >> s;
//		for(int j = 0; j < s; j++){
//			cin >> name;
//			q[name].push_back(course);
//		}
//	}
//	int cnt2 = 0;
//	for(int i = 0; i < n; i++){
//		cin >> name;
//		int cnt = 0;
//		if(cnt2 != 0) cout << endl;
//		cout << name;
//		cout <<" "<<q[name].size();
//		sort(q[name].begin(), q[name].end());
//		for(auto j = q[name].begin(); j != q[name].end(); j++) {	
//			cout << " " << *j;
//		}
//		cnt2++;
//			
//	}
//	return 0;
//}

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int getid(char *name) {
	int id = 0;
	for(int i = 0; i < 3; i++)
		id = 26 * id + (name[i] - 'A');
	id = id * 10 + (name[3] - '0');
	return id;
}

const int maxn = 26 * 26 * 26 * 10 + 10;
vector<int> v[maxn];

int main() {
	int n, k, no, num, id = 0;
	char name[5];
	scanf("%d %d", &n, &k);
	for(int i = 0; i < k; i++){
		scanf("%d %d", &no, &num);
		for(int j = 0; j < num; j++) {
			scanf("%s", name);
			id = getid(name);
			v[id].push_back(no);
		}
	}
	for(int i = 0; i < n; i++) {
		scanf("%s", name);
		id = getid(name);
		sort(v[id].begin(), v[id].end());
		printf("%s %lu", name, v[id].size());
		for(int j = 0; j < v[id].size(); j++)
			printf(" %d", v[id][j]);
		printf("\n");
	}
}