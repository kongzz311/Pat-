// 
#include <iostream>

using namespace std;

int main() 
{
	int a[100];
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	int sum = 0;
	int now = 0;
	
	for(int i = 0; i < n; i++) {
		if(a[i] > now) {
			sum += (a[i] - now)*6 + 5;
			now = a[i];
		} else if(a[i] < now) {
			sum += (now - a[i])*4 + 5;
			now = a[i];
		} else {
			sum += 5;
			now = a[i];
		}
	}
	
	printf("%d", sum);
	
	return 0;
}