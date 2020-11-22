#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long t;
	long long a, x, y, b;
	cin >> a >> x >> b >> y;
	cin >> t;
	long long first = a + 21 * (max(0ll, t - 30) * x );
	long long second = b + 21 * (max(0ll, t - 45) * y);
	cout << first << " " << second << "\n";
}
