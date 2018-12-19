#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> pre, post, in;

int main() 
{
	cin >> n;
	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		pre.push_back(temp);
	}
	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		post.push_back(temp);
	}
	return 0;
}