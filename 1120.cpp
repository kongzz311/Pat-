#include <iostream>
#include <set>
using namespace std;
set<int> s;
int convert(int n){
	int ans = 0;
	string s1 = to_string(n);
	for(int i = 0; i < s1.length(); i++)
		ans += s1[i] - '0';
	return ans;
}
int main() 
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		s.insert(convert(temp));
	}
	cout << s.size() << endl;
	for(auto i = s.begin(); i != s.end(); i++){
		if(i != s.begin()) cout << " ";
		cout << *i;
	}
	return 0;
}