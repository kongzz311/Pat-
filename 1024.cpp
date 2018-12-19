// 
#include <iostream>

using namespace std;

string a, b;
int k;

bool judge(string a){
	int n = a.length();
	for(auto i = 0; i < n/2; i++) {
		if(a[i] != a[n-1-i])
			return false;
	}
	return true;
}

void add() {
	string x = "1";
	int carry = 0;
	int n = a.length();
	b = a;
	for(int i = 0; i < n; i++) {
		int temp = a[n-i-1] -'0' + b[i] -'0' + carry;
		carry = temp/10;
		a[n-i-1] = '0' + temp % 10;
	}
	if(carry == 1)
		a = x + a;
}

int main() 
{
	cin >> a >> k;
	
	int cnt = 0;
	
	if(judge(a))
	{
		cout << a << endl;
		cout << cnt;
		return 0;
	}
	
	while(cnt < k) {
		add();
		cnt++;
		if(judge(a))
		{
			cout << a << endl;
			cout << cnt;
			return 0;
		}
		
		

	}
	
	cout << a << endl;
	cout << k;
	
	return 0;
}