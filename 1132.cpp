#include <iostream>
#include <cmath>
using namespace std;
int main() 
{
	long long test;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> test;
		int j = 1;
		while(test/((long long)pow(10, j))) j++;
		int half = j / 2;
		long long pre = test / (long long)pow(10, half);
		long long next = test % (long long)pow(10, half);
		if(pre != 0 && next != 0 && test % (pre * next) == 0) cout << "Yes\n";
		else cout << "No\n"; 
	}
	return 0;
}