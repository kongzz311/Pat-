#include <iostream>
#include <string>
using namespace std;

int main() 
{
	string s;
	int ans = 1;
	getline(cin, s);
	for(int i = 0; i < s.length(); i++) {
		int delta = 0;
		while( (i-delta >= 0) && (i + delta < s.length()) && s[i-delta] == s[i+delta])
		delta++;
		if(1 + 2 * (delta - 1) > ans)
			ans = 1 + 2 * (delta - 1);
		
		delta = 0;
		while( (i-delta>= 0) && (i + delta + 1< s.length()) && s[i-delta] == s[i+delta + 1])
		delta++;
		if(2 * delta > ans)
			ans = 2 * delta;
	}
	cout << ans;
	return 0;
}