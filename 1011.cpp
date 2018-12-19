// 
#include <iostream>

using namespace std;

int main() 
{
	char oc[3] = {'W', 'T', 'L'};
	float d[3][3];
	for(int i = 0; i < 3; i++) {
		cin >> d[i][0] >> d[i][1] >> d[i][2];
	}
	
	float ans[3];
	for (int i = 0; i < 3; i++) {
		float max = -1;
		int index = 0;
		for(int j = 0; j < 3; j++) {
			if(d[i][j] > max)
			{
				index = j;
				max = d[i][j];		
			}
		}
		ans[i] = max;
		cout << oc[index] <<" ";
	}
	
	float sum = 1;
	for (int i = 0; i < 3; i++) {
		sum *= ans[i];
	}
	
	sum = (sum * 0.65-1)*2;
	printf("%.2f", sum);
	return 0;
}