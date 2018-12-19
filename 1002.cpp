// 
#include <iostream>

using namespace std;

int main() 
{
	double poly[1001] = {0};
	int k, cnt=0;
	for (int j = 0; j < 2; j++) {
		cin >> k;
		for (int i = 0; i < k; i++) {
			double a;
			int p;
			cin >> p;
			cin >> a;
			poly[p] += a;
		}
	}
	
	for (int i = 0; i < 1001; i++) {
		if(poly[i] != 0.0)
			cnt++;
	}
	
	cout << cnt;
	for (int i = 1000; i >= 0; i--) {
		if(poly[i] != 0.0)
		{
			printf(" %d %.1f", i, poly[i]);
		}
	}
	
	return 0;
}