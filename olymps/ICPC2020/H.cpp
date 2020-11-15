#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		long long Monster, People, strongMonster, strongPeople;
		cin >> Monster >> strongMonster >> People >> strongPeople;
		bool flag1 = (strongMonster == 0) && (strongPeople == 0);
		bool flag2 = (strongPeople == 0) && (People < Monster + 2) && (Monster > 1);
		bool flag3 = (strongMonster == 0) && (Monster != People) && (People < Monster + 1) && (Monster == 2);
		bool flag4 = (strongMonster == 0) && (People < Monster + 2) && (Monster > 2);
		bool flag5 = (Monster == People) && (Monster > 3);
		if (flag1 || flag2 || flag3 || flag4 || flag5) {
			cout << "No\n";
		}
		else{
			cout << "Yes\n";
		}
	}
}
