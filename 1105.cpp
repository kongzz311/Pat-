#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
bool cmp(int x, int y){
	return x > y;
}
int func(int N) {
int i = sqrt((double)N); 
while(i >= 1) {
if(N % i == 0)
return i;
i--; 
} return 1;
}
int main() 
{
	int num;
	cin >> num;
	vector<int> a(num);
	for(int i = 0; i < num; i++)
		cin >> a[i];
	sort(a.begin(), a.end(), cmp);
	int m, n;
//	m = int(sqrt(num)) + 1;
//	while(num%m) m--;
	n = func(num);
	m = num/n;
	int b[m][n];
	int t = 0;
	int level = m / 2 + m % 2;
	for(int i = 0; i < level; i++){
		for(int j = i; j <= n - 1 - i && t <= num - 1; j++)
			b[i][j] = a[t++];
		for(int j = i + 1; j <= m - 2 - i && t <= num - 1; j++)
			b[j][n-1-i] = a[t++];
		for(int j = n - i - 1; j >= i && t <= num - 1; j--)
			b[m-1-i][j] = a[t++];
		for(int j = m - 2 - i; j >= i + 1 && t <= num -1; j--)
			b[j][i] = a[t++];
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			printf("%d", b[i][j]);
			if(j != n-1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}