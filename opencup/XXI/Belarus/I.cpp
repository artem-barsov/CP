#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int ayellow = 0;
	int bred = 0;
	int value;
	for (int i = 0; i < n; ++i) {
		cin >> value;
		if (value == 0) ++ayellow;
	}
	for (int i = 0; i < m; ++i) {
		cin >> value;
		if (value != 0) ++bred;
	}
	for (int i = 0; i < k; ++i) {
		cin >> value;
	}
	cout << abs(ayellow - bred) << "\n";
}
