// 
#include <iostream>
#include <vector>

using namespace std;

vector<long long> ans;

void convert(int n, int k) {
	
	long long m = 0;	
	while(n != 0) {
		m = n % k;
		ans.push_back(m);
		n /= k;
	}
	
}

bool judge() {
	int end = ans.size() - 1;
	bool flag = true;
	for(int i = 0; i <= end/2; i++) {
		if(ans[i] != ans[end - i]) {
			flag = false;
			break;
		}
	}
	
	return flag;
}

void answer() {
	int ind = 0;
	for(auto i = ans.rbegin(); i != ans.rend(); i++) {
		if(ind == 0) 
		{
			cout << *i;
			ind++;
		}
		else {
			cout << " " << *i;
		}
	}
}

int main() 
{
	long long n, k;
	cin >> n >> k;
	convert(n, k);
	if(!judge()) cout << "No\n";
	else cout << "Yes\n";
	
	answer();
	
	return 0;
}