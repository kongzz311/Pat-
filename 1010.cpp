// 
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <climits>

using namespace std;

long long convert(string s, int radix) {
	long long sum = 0;
	int index = 0, temp = 0;
	for(auto i = s.rbegin(); i != s.rend(); i++) {
		temp = isdigit(*i)? *i - '0' : *i - 'a' + 10;
		if(sum + temp * pow(radix, index+1) > LLONG_MAX) 
		{
			return -1;
		}
		sum += temp * pow(radix, index++);
	}
	return sum;
}

long long findradix(string s, long long num) {
	char i = *max_element(s.begin(), s.end());
	long long l = (isdigit(i)? i - '0' : i - 'a' + 10)+1;
	long long h = max(l, num);
	while(l <= h) {
		long long mid = (l + h) /2;
		long long t = convert(s, mid);
		if(t == -1) 
		{
			h = mid -1;
			continue;
		}
		if(t > num) h = mid - 1;
		else if(t == num) return mid;
		else l = mid + 1;
	}
	
	
	return -1;
}


int main() 
{
	long long index, tag, radix, radixNum;
	string s1, s2;
	cin >> s1 >> s2 >> tag >> radix;
	long long flag = tag == 1 ? findradix(s2, convert(s1, radix)) : findradix(s1, convert(s2, radix));
	
	if(flag == -1)
		cout << "Impossible";
	else {
		cout << flag;
	}
	
	
	
	return 0;
}