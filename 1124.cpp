#include <iostream>
#include <map>
#include <set>
using namespace std;
map<string, bool> in;
set<string> ss;
map<int, string> sheet;
int main() 
{
	int n, m, s, cnt = 0;
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i++){
		string temp;
		cin >> temp;
//		if(!in[temp]){
//			in[temp] = true;
		sheet[i] = temp;
//		ss.insert(temp);
//		}
	}
//	cout << endl;
	if(n< s)
		cout << "Keep going...";
	else {
		for(int i = 1; i <= n; i++){
			if(i>=s && (i - s) % m == 0){
				if(!in[sheet[i]]){
					in[sheet[i]] = true;
					cout << sheet[i] << endl;
				}
				else {
//					in[sheet[i+1]] = true;
//					cout << sheet[i+1] << endl;
					s++;
				}
			}
		}
	}
	return 0;
}