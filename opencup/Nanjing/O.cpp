#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << 0 << '\n';
		return 0;
	}
	int corner = (n-2)*(n-2);
	int edge = n*n - corner;
	cout << fixed << corner * sqrt(2) + edge << "\n";
}
