// 
#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, int> b;
int main() 
{
	int n;
	cin >> n;
	vector<int> a;
	for(int i  = 0; i < n; i++){
		int temp;
		cin >> temp;
		a.push_back(temp);
		b[temp]++;
	}
	for(auto i = a.begin(); i != a.end(); i++) {
		if(b[*i] == 1)
		{
			cout << *i;
			return 0;
		}
	}
	
	cout << "None";
	return 0;
}