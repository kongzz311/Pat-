#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main() {
	char c[81], u[30][30];
	fill(u[0], u[0] + 900, ' ');
	scanf("%s", c);
	int n = strlen(c) + 2;
	int n1 = n/3, n2 = n/3 + n%3, ind = 0;
	for(int i = 0; i < n1; i++) u[i][0] = c[ind++];
	for(int i = 1; i <= n2 - 2; i++) u[n1-1][i] = c[ind++];
	for(int i = n1 - 1; i >= 0; i--) u[i][n2-1] = c[ind++];
	for(int i = 0; i < n2; i++) {
		for(int j = 0; j < n2; j++)
			printf("%c", u[i][j]);
		printf("\n");
	}
	return 0;
} 