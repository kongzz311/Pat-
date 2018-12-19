// 
#include <iostream>

using namespace std;

int main() 
{
	int a, b, c;
	cin >> a >> b >> c;
	char ans[6];
	
	ans[0] = (a/13) < 10 ? (a/13) + '0' :  (a/13 - 10) + 'A';    
	ans[1] = (a%13) < 10 ? (a%13) + '0' :  (a%13 - 10) + 'A';
	ans[2] = (b/13) < 10 ? (b/13) + '0' :  (b/13 - 10) + 'A';    
	ans[3] = (b%13) < 10 ? (b%13) + '0' :  (b%13 - 10) + 'A';
	ans[4] = (c/13) < 10 ? (c/13) + '0' :  (c/13 - 10) + 'A';    
	ans[5] = (c%13) < 10 ? (c%13) + '0' :  (c%13 - 10) + 'A';
	
	
	cout <<'#';
	for(int i = 0; i < 6; i++) cout << ans[i];
	return 0;
}