// 
#include <iostream>
#include <climits>

using namespace std;

int main() 
{
	int a[200005];

	int a1, b1;
	int mid, temp;
	
	scanf("%d", &a1);
	for(int i = 0; i < a1; i++) {
		scanf("%d", &a[i]);
	}
	
	a[a1] = INT_MAX;	
	
	scanf("%d", &b1);	
	mid = (a1 + b1 + 1)/2;
	int i = 0, cnt = 0;
	
	for(int j = 0; j < b1; j++) {
		scanf("%d", &temp);
		while(a[i] < temp) {
			cnt++;
			if(cnt == mid) cout << a[i];
			i++;
		}
		cnt++;
		if(cnt == mid) cout << temp;
		
	}
	
	while(i < a1) {
		cnt++;
		if(cnt == mid) cout << a[i];
		i++;
	}
	
	

	
	

	return 0;
}