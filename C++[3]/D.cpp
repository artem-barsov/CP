#define _CRT_DISABLE_PERFCRIT_LOCKS
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> x(n);
	set<int> known;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		if (x[i]) known.insert(x[i]);
	}
	int minnum = 0, check = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] == 0) {
			while (known.find(++minnum) != known.end());
			x[i] = minnum;
		}
		check += ((x[i]&1) ? x[i] : -x[i]);
	}
	if (abs(check) == (n+(n&1))/2) {
		cout << n << '\n';
		for (int i = 0; i < n; i++) cout << x[i] << ' ';
	}
	else cout << -1;
}
