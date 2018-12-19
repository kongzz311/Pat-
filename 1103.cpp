#include <iostream>
#include <algorithm>
using namespace std;
string  add(string s){
	int carry = 0;
	string rs = s;
	reverse(rs.begin(), rs.end());
	for(int i = s.size() - 1; i>=0; i--){
		int num = s[i] + rs[i] - '0' - '0' + carry;
		if(num >= 10){
			s[i] = num%10 + '0';
			carry = 1;
		}else{
			s[i] = num%10 + '0';
			carry = 0;
		}
	}
	if(carry == 1)
		s = "1" + s;
	return s;
}
int main() 
{
	string s, rs;
	cin >> s;
	rs = s;
	int cnt = 1;
	reverse(rs.begin(), rs.end());
	while(cnt <= 10 && s != rs){
		cout << s << " + "<< rs <<" = " << add(s) << endl;
		s = add(s);
		rs = s;
		reverse(rs.begin(), rs.end());
		cnt++;
	}
	
	if(cnt <= 10) {
		cout << s <<" is a palindromic number.";
	}
	else cout << "Not found in 10 iterations.";
	return 0;
}