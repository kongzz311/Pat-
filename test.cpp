#include <iostream>
#include <climits>
using namespace std;


int main(){
	double a = 0.5;
	for (int i = 0; i < 10; i++) {
		printf("%.0f\n", a+i);
	}
	return 0;
}