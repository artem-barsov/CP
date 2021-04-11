#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;
	if ( k == 1) {
		cout << "Yes\n";
		return 0;
	}
	if ( (k == 2) && (n % 2 == 0)) {
		cout << "Yes\n";
		return 0;
	}
	if ( (n == 4) && (k == 3) ) {
		cout << "Yes\n";
		return 0;
	}
	cout << "No\n";
}
