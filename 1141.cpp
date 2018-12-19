#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
struct institution{
	float tws = 0;
	string name;
	int ns = 0;
}Ins[10010];
map<string, bool> exist;
map<string, int> n2data;
int n;
bool cmp1(institution x, institution y){
	if(x.tws != y.tws)
		return x.tws > y.tws;
	else if(x.tws == y.tws){
		if(x.ns!=y.ns)
			return x.ns < y.ns;
		else
			return x.name < y.name;
	}
}
string revert(string s){
	for(int i = 0; i < s.length(); i++){
		if(s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] - 'A' + 'a';
	}
	return s;
}
int main() 
{
	int cnt = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		string id;
		int grade;
		string insN;
		cin >> id >> grade >> insN;
		insN = revert(insN);
		if(!exist[insN]){
			exist[insN] = true;
			n2data[insN] = cnt;
			Ins[cnt].name = insN;
			cnt++;
		}
		int ind = n2data[insN];
		Ins[ind].ns++;
		float weight;
		if(id[0]=='B') weight = 1/1.5;
		if(id[0]=='A') weight = 1;
		if(id[0]=='T') weight = 1.5;
		Ins[ind].tws += weight*grade;
	}
	sort(Ins, Ins + cnt, cmp1);
	cout << cnt << endl;
	int j = 1;
	for(int i = 0; i < cnt; i++){
		if(i!=0){
			if(int(Ins[i].tws) != int(Ins[i-1].tws))
				j = i + 1;
		}
		cout << j << " " << Ins[i].name << " " << int(Ins[i].tws) << " " << Ins[i].ns<<endl;

	}
	return 0;
}