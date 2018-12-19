// 
#include <iostream>


using namespace std;

int main() 
{
	string s[10] = {"zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	string a;
	cin >> a;
	
	int sum = 0;
	
	for(int i = 0; i < a.length(); i++) sum += a[i]-'0';	
	
	string c = to_string(sum);
	for(int i = 0; i < c.length(); i++){
		if(i == 0)
			cout << s[c[i] - '0'];
		else 
			cout <<" "<< s[c[i] - '0'];		
	}
	return 0;
}