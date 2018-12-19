// 
#include <iostream>
#include <vector>

using namespace std;

int n;

vector<int> a(31);
vector<int> b(31);
vector<int> c(100000, -1);

void convert(int root, int start, int end, int index) {
	if(start > end) return;
	int i = start;
	while(i < end && b[i] != a[root]) i++;
	c[index] = a[root];
	convert(root - (end - i) - 1, start, i - 1, 2 * index + 1);
	convert(root - 1, i + 1, end, 2 * index + 2);
}

int main() 
{

	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < n; i++) scanf("%d", &b[i]);
	
	convert(n - 1, 0, n - 1, 0);
	
	int cnt = 0;
	for(int i = 0; i < 100000; i ++) {
		if(c[i] != -1) {
			if(cnt != 0) printf(" ");
			printf("%d", c[i]);
			cnt++;
		}
		
		if(cnt == n) break;
	}
	
	return 0;
}