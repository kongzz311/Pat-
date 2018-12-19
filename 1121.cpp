#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
//map<string, bool> singledog;
map<int, bool> invited;
set<int> s;
int a2b[100000];
vector<int> inv;
int main() 
{
	fill(a2b, a2b+100000, -1);
	int s1, s2;
	int n, m;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s1 >> s2;
		a2b[s1] = s2;
		a2b[s2] = s1;
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> s1;
		inv.push_back(s1);
		invited[s1] = true;
	}
	invited[-1] = false;
	for(int i = 0; i < m; i++){
		if(!invited[a2b[inv[i]]])
			s.insert(inv[i]);
	}
	cout << s.size() << endl;
	for(auto i = s.begin(); i != s.end(); i++){
		if(i!= s.begin()) cout << " ";
		printf("%05d", *i);
	}
	return 0;
}