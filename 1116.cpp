#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<bool> isprime;
bool checked[10000];
map<int, int> name2index;
map<int, int> index2name;
bool isPrime(int n){
	if(n==0 || n == 1) return false;
	for(int i = 2; i * i <= n; i++)
		if(n%i == 0) return false;
	return true;
}
int main() 
{
	int n, k;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int name;
		scanf("%d", &name);
		name2index[name] = i;
		index2name[i] = name;
	}
	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		int name;
		scanf("%d", &name);
		
		if(name2index[name] == 0)
			printf("%04d: Are you kidding?\n", name);
		else if(checked[name]){
			printf("%04d: Checked\n", name);
		}
		else if(name2index[name] == 1)
			printf("%04d: Mystery Award\n", name);
		else if(isPrime(name2index[name]))
			printf("%04d: Minion\n",  name);
		else 
			printf("%04d: Chocolate\n", name);
		checked[name] = true;
	}
	return 0;
}