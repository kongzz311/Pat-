#include <iostream>
#include <set>
using namespace std;
int book[50001];
struct node {
	int value, cnt;
	friend bool operator < (node x, node y){
		return (x.cnt!=y.cnt) ? x.cnt < y.cnt : x. value < y.value;
	}
};
int main(){
	int n, k, num;
	cin >> n >> k;
	set<node> s;
	for(int i = 0; i < n; i++){
		cin >> num;
		if(i != 0){
			cout << num <<":";
			int tempcnt = 0;
			for(auto it = s.begin(); tempcnt < k && it!= s.end(); it++){
				cout<<" "<< it->value;
				tempcnt++;
			}
			cout << endl;
		}
		auto it = s.find(node{num, book[num]});
		if(it != s.end()) s.erase(it);
		book[num]++;
		s.insert(node{num, book[num]});
	}
	return 0;
}
