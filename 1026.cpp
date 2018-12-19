#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct person {
	int arrive, start, time;
	bool vip;
}tempperson;

struct tablenode {
	int end = 8 * 3600, num;
	bool vip;
};

bool cmp1(person a, person b) {
	return a.arrive < b.arrive;
}

bool cmp2(person a, person b) {
	return a.start < b.start;
}

vector<person> player;
vector<tablenode> table;

void alloctable(int personid, int tableid){
	if(player[personid].arrive <= table[tableid].end)
		player[personid].start = table[tableid].end;
	else {
		player[personid].start = player[personid].arrive;
	}
	table[tableid].end = player[personid].start + player[personid].time;
	teble[tableid].num++;
}



