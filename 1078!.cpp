// 
#include <iostream>
using namespace std;
int size, n, hashTable[10100];

bool prime(int n ) {
	if(n <= 1) return false;
	for(int i = 2; i * i <= n; i++) {
		if(n%i == 0) return false;
	}
	return true;
}

void insert(int key) {
	for(int step = 0; step < size; step++) {
		int ind = (key + step * step) % size;
		if(hashTable[ind] == 0) {
			hashTable[ind] = 1;
			cout << ind ;
			return;
		}
	}	
	cout << '-';
}

int main() 
{
	cin >> size >> n;
	while(!prime(size)) size++;
	for(int i = 0; i < n; i++) {
		int key;
		cin >> key;
		if(i != 0) cout << ' ';
		insert(key);
	}
	return 0;
}