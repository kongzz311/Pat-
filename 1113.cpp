#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(int x, int y){
	return x > y;
}
vector<int> a;
int main() 
{
	long long sum1 = 0, sum2;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		a.push_back(t);
	}
	sort(a.begin(), a.end(), cmp);
	int mid = n%2 == 0 ? n/2 : n/2 + 1;
	for(int i = 0; i < mid; i++)
		sum1 += a[i];
	for(int i = mid; i < n; i++)
		sum2 += a[i];
	cout << n%2 << " " << sum1 - sum2;
	return 0;
}