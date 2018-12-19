// 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n1, n2;
long long ans;

vector<int> c_plus;
vector<int> c_minus;
vector<int> p_plus;
vector<int> p_minus;

bool cmp1(int a, int b){
	return a > b;
}

bool cmp2(int a, int b){
	return a < b;
}
int main() 
{
	cin >> n1;
	for(int i = 0; i < n1; i++){
		int temp;
		cin >> temp;
		if(temp >= 0)
			c_plus.push_back(temp);
		else 
			c_minus.push_back(temp);		
	}
	cin >> n2;
	for(int i = 0; i < n2; i++){
		int temp;
		cin >> temp;
		if(temp >= 0)
			p_plus.push_back(temp);
		else 
			p_minus.push_back(temp);		
	}
	sort(c_plus.begin(), c_plus.end(), cmp2);
	sort(p_plus.begin(), p_plus.end(), cmp2);
	sort(c_minus.begin(), c_minus.end(), cmp1);
	sort(p_minus.begin(), p_minus.end(), cmp1);
	
	while((!c_plus.empty())&&(!p_plus.empty())){
		ans += c_plus.back() * p_plus.back();
		c_plus.pop_back();
		p_plus.pop_back();
	}
	while((!c_minus.empty())&&(!p_minus.empty())){
			ans += c_minus.back() * p_minus.back();
			c_minus.pop_back();
			p_minus.pop_back();
	}
	cout << ans;
	return 0;
}