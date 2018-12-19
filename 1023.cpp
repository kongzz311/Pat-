// 
#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<char, int> a;



int main() 
{
	string s1;
	cin >> s1;
	int carry = 0;
	vector<char> s2;
	for(auto i = s1.rbegin(); i != s1.rend(); i++) {
		s2.push_back(((*i-'0' )*2 + carry) % 10 + '0');
		carry = ((*i-'0')*2 + carry)/ 10;	
	}
	if(carry != 0)
	s2.push_back(carry + '0');
	
	for(char i = '0'; i <= '9'; i++) {
		a[i] = 0;
	}
	
	for(auto i = s1.begin(); i != s1.end(); i++){
	
		a[*i]++;
	}
	
	
	for(auto i = s2.begin(); i != s2.end(); i++){
	
		a[*i]--;
	}
	
	int flag = 1;
	
	for(char i = '0'; i <= '9'; i++) {
			if(a[i] != 0)
				flag = 0;
	}
	
	if(flag == 1)
	{
		cout << "Yes\n";
		for(auto i = s2.rbegin(); i != s2.rend(); i++) {
			cout << *i;
		}
	}
	else {
		cout << "No\n";
		for(auto i = s2.rbegin(); i != s2.rend(); i++) {
			cout << *i;
		}
	}
	
	return 0;
}