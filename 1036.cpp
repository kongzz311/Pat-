// 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct student{
	string name;
	char gender;
	string id;
	int grade;	
};
int n, cntf = 0, cntm = 0;
vector<student> male;
vector<student> female;

bool cmp1(student a, student b) {
	return a.grade > b.grade;
}

int main() 
{
	cin >> n;
	male.resize(n);
	female.resize(n);
	for(int i = 0; i < n; i++) {
		string tname;
		char tgender;
		string tid;
		int tgrade;
		cin >> tname >> tgender >> tid >> tgrade;
		if(tgender == 'M'){
			male[cntm].name = tname;
			male[cntm].gender = tgender;
			male[cntm].id = tid;
			male[cntm].grade = tgrade;
			cntm++;
		}else{
			female[cntf].name = tname;
			female[cntf].gender = tgender;
			female[cntf].id = tid;
			female[cntf].grade = tgrade;
			cntf++;
		}
		
	}
	
	sort(male.begin(), male.begin() + cntm, cmp1);
	sort(female.begin(), female.begin() + cntf, cmp1);
	
	if(cntf == 0)
		cout << "Absent" << endl;
	else 
		cout << female[0].name << " " << female[0].id<<endl;
	if(cntm == 0)
		cout << "Absent" << endl;
	else 
		cout << male[cntm-1].name << " " << male[cntm-1].id<<endl;
	if(cntm == 0 || cntf == 0)
		cout << "NA";
	else 
		cout << female[0].grade - male[cntm-1].grade;

	
	
	return 0;
}