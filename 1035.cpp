// 
#include <iostream>
#include <map>
using namespace std;

map<int, string> a;
map<int, string> b;


int main() 
{
	int n, cnt = 0, flag = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		flag = 0;
		for(auto i = s2.begin(); i != s2.end(); i++) {
			if(*i == '1'){
				*i = '@';
				flag = 1;
			}
			if(*i == '0'){
				*i = '%';
				flag = 1;
			}
			if(*i == 'l'){
				*i = 'L';
				flag = 1;
			}
			if(*i == 'O'){
				*i = 'o';
				flag = 1;
			}
		}
		if(flag == 1) {
			a[cnt] = s1;
			b[cnt] = s2;
			cnt++;
		}
	}
	if(n == 1 && cnt == 0)
		cout << "There is 1 account and no account is modified";
	else if(n != 1 && cnt == 0)
		cout <<"There are " <<n<<" accounts and no account is modified";
	else if(cnt != 0){
		cout << cnt << endl;
		for(int i = 0; i < cnt; i++) {
			cout << a[i] << " " << b[i] << endl;
		}
	}
		
	return 0;
}