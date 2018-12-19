#include <iostream>
#include <vector>
using namespace std;
int main() 
{
	int n;
	cin >> n;
	vector<double> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	double ans = 0;
	for(int i = 0; i < n; i++)
		ans += a[i]*(n-i) * (i+1);
	printf("%.2f", ans);
	return 0;
}