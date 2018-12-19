// 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct student{
	string s;
	int loc, score;
	int final_rank, local_rank;
}stu[30000]; //每个考场300啦

int location, n, k, ind;

bool cmp1(student a, student b) {
	return a.score != b.score ? a.score > b.score : a.s < b.s; 
}

int main() 
{
	ind = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> k;
		int temp = ind;
		for(int j = 0; j < k; j++) {
			stu[ind].loc = i;
			cin >> stu[ind].s >> stu[ind].score;
			ind++;
		}
		sort(&stu[temp], &stu[temp + k], cmp1);
		stu[temp].local_rank = 1;	
		for(int a = temp + 1; a < temp + k ; a++) {
			stu[a].local_rank = a - temp + 1;
			if(stu[a].score == stu[a - 1].score) 
				stu[a].local_rank = stu[a-1].local_rank;
		}
		
	}
	
	sort(stu, stu + ind, cmp1);
	stu[0].final_rank = 1;	
	for(int a = 1; a < ind; a++) {
		stu[a].final_rank = a + 1;
		if(stu[a].score == stu[a - 1].score) 
			stu[a].final_rank = stu[a-1].final_rank;
	}
	
	cout << ind << endl;
	for(int i = 0; i < ind; i++) {
		cout << stu[i].s<<" "<<stu[i].final_rank<<" "<<stu[i].loc<<" "<<stu[i].local_rank<<endl;;
	}
	
	return 0;
}