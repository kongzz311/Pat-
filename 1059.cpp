// 
#include <iostream>

using namespace std;

int main() 
{
	long long a, b, c, d, e, f, ans1, ans2, ans3;
	scanf("%lld.%lld.%lld", &a, &b, &c);
	scanf("%lld.%lld.%lld", &d, &e, &f);
	long long carry = 0;
	ans3 = (c + f) % 29;
	carry = (c + f) / 29;
	ans2 = (b + e + carry) % 17;
	carry = (b + e + carry) / 17;
	ans1 = a + d + carry;
	
	printf("%lld.%lld.%lld", ans1, ans2, ans3);
	return 0;
}