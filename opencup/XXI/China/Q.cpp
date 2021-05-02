#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
	cin >> n >> k;
	if ( k == 0 ) {
		cout << -3.0 << " " << 3.0 << "\n";
		return 0;
	}
	int value;
	long double sum = 0.0;
	for (int i = 0; i < k; ++i) {
		cin >> value;
		sum += value;
	}
	long double min = sum + (-3.0) * (n - k);
	long double max = sum + 3.0 * (n - k);
	min /= n;
	max /= n;
	cout.precision(10);
	cout << min << " " << max << "\n";
}
