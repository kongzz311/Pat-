// 
#include <iostream>
#include <climits>
using namespace std;

int main() 
{
	int l=0, r = 0, n;
	scanf("%d", &n);
	int a[n];
	r = n-1;
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int sum = -1;
	int temp = 0;
	int tempindex = 0;
	
	for(int i = 0; i < n; i++){
		temp += a[i];
		if(temp < 0) {
			temp = 0;
			tempindex = i + 1;
		}
		else if(temp > sum){
			sum = temp;
			l = tempindex;
			r = i;
		}
	}
	
	if(sum < 0) sum = 0;
	printf("%d %d %d", sum, a[l], a[r]);
	
	return 0;
}