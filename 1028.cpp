// 
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;


struct node {
	int id;
	char name[10];
	int grade;
};

bool cmp1(node a, node b) {
	return a.id <= b.id;
}

bool cmp2(node a, node b) {
	if(strcmp(a.name, b.name) == 0) return a.id < b.id; 
	return strcmp(a.name, b.name) <= 0;
}

bool cmp3(node a, node b) {
	return a.grade <= b.grade;
}

int main() 
{
	int n, m;
	scanf("%d%d", &n, &m);
	vector<node> all(n);
	for(int i = 0; i < n; i++) {
		scanf("%d %s %d", &all[i].id, all[i].name, &all[i].grade);
	}
	
	if(m == 1)
		sort(all.begin(), all.end(), cmp1);
	if(m == 2)
		sort(all.begin(), all.end(), cmp2);
	if(m == 3)
		sort(all.begin(), all.end(), cmp3);
	
	for(int i = 0; i < n; i++) {
		printf("%06d %s %d\n", all[i].id, all[i].name, all[i].grade);
	}
	return 0;
}