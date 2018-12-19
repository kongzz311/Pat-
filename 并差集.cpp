#include <iostream>
using namespace std;
// findfather
int findFather(int x){
	int a = x;
	while(x!=father[x]){
		x = father[x];
	}
	while(a!=x){
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

int findfather(int x){
	if(x == father[x]) return x;
	else{
		int f = findFather(father[x]);
		father[x] = f;
		return f;
	}
}
// Union
void Union(int a, int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB){
		father[faA] = faB;
	}
}

int main() 
{
	// initialize
	for(int i = 1; i <= n; i++){
		father[i] = i;
	}
	//findfather
	
	return 0;
}