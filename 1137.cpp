#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
struct node{
	string id;
	int gp, gm = -1, gf = -1, g = -1;	
}stu[10010];
map<string, int> id2i;
bool cmp1(node x, node y){
	return x.g == y.g ? x.id < y.id : x.g > y.g;
}
int main() 
{
	int p, m, n, cnt = 1;
	cin >> p >> m >> n;
	for(int i = 0; i < p; i++){
		string id;
		int g;
		cin >> id >> g;
		if(g < 200) continue;
		else {
			stu[cnt].id = id;
			stu[cnt].gp = g;
			id2i[id] = cnt;
			cnt++;
		}
	}
	for (int i = 0; i < m; i++) {
		string id;
		int g;
		cin >> id >> g;
		if(id2i[id] == 0) continue;
		else {
			int ind = id2i[id];
			stu[ind].gm = g;
		}
	}
	for (int i = 0; i < n; i++) {
		string id;
		int g;
		cin >> id >> g;
		if(id2i[id] == 0) continue;
		else {
			int ind = id2i[id];
			stu[ind].gf = g;
			if(stu[ind].gm != -1 && stu[ind].gm > stu[ind].gf){
				stu[ind].g = int(round(stu[ind].gm * 0.4 + stu[ind].gf * 0.6 ));
			}
			else {
				stu[ind].g = g;
			}
		}
	}
	sort(stu, stu + cnt, cmp1);
	for(int i = 0; i < cnt; i++){
		if(stu[i].g != -1 && stu[i].g >= 60 ){
			cout << stu[i].id << " " << stu[i].gp << " " << stu[i].gm << " " << stu[i].gf<< " " << stu[i].g<<endl;
 		}
	}
	return 0;
}