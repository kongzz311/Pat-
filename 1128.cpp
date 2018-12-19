#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int main() 
{
	cin >> n;
	for(int i = 0; i < n; i++){
		int flag = 1;
		cin >> m;
		set<int> all;
		vector<int> in(m);
		for(int j = 0; j < m; j++){
			int temp;
			cin >> temp;
			all.insert(temp);
			in[j] = temp;
			for(int k = 0; k < j; k++)
			{
				if(abs(in[k]-temp)==j-k)
					flag = 0;			
			}

		}
		if(all.size()==m && flag==1)
			cout << "YES\n";
		else
			cout << "NO\n";
		
	}
	return 0;
}