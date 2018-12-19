//#include <iostream>
//#include <vector>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//vector<int> s;
//vector<int> a;
//int main() 
//{
//	char st[50];
//	int n;
//	cin >> n;
//	for(int i = 0; i < n; i++){
//		scanf("%s", st);
//		if(!strcmp(st, "Pop")){
//			if(s.size() == 0)
//				printf("Invalid\n");
//			else{
//				printf("%d\n", s.back());
//				s.pop_back();
//			}
//		}
//		else if(!strcmp(st, "Push")){
//			int temp;
//			scanf("%d", &temp);
//			s.push_back(temp);
//		}
//		else if(!strcmp(st, "PeekMedian")){
//			int n = s.size();
//			if(n == 0){
//				printf("Invalid\n");
//			}else {
//				if(n%2==0){
//					a = s;
//					sort(a.begin(), a.end());
//					int med = n/2;
//					printf("%d\n",a[med-1]);
//				}
//				else {
//					a = s;
//					sort(a.begin(), a.end());
//					int med = (n+1)/2;
//					printf("%d\n",a[med-1]);
//				}
//			}
//		}
//	}
//	return 0;
//}

// 超时了

#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int maxn = 100010;
const int sqrN = 316;

stack<int> st;
int block[sqrN];
int table[maxn];

void peekMedian(int k){
	int sum = 0;
	int idx = 0;
	while (sum + block[idx] < k) {
		sum += block[idx++];
	}
	int num = idx * sqrN;
	while (sum + table[num] < k) {
		sum += table[num++];
	}
	printf("%d\n", num);
}
void push(int x){
	st.push(x);
	block[x/sqrN]++;
	table[x]++;
}
void pop(){
	int x = st.top();
	st.pop();
	block[x/sqrN]--;
	table[x]--;
	printf("%d\n", x);
}
int main(){
	int x, query;
	memset(block, 0, sizeof(block));
	memset(table, 0, sizeof(table));
	char cmd[20];
	scanf("%d", &query);
	for(int i = 0; i < query; i++){
		scanf("%s", cmd);
		if(!strcmp(cmd, "Push")){
			scanf("%d", &x);
			push(x);
		}else if(!strcmp(cmd, "Pop")){
			if(st.empty() == true){
				printf("Invalid\n");
			}else{
				pop();
			}
		} else{
			if(st.empty() == true){
				printf("Invalid\n");
			}else {
				int k = st.size();
				if(k%2 == 1) k = (k + 1)/2;
				else k = k / 2;
				peekMedian(k);
			}
		}
	}
	return 0;
}

