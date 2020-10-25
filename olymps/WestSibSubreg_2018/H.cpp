#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
	long long n = 0, x1, y1, x2, y2;
	cin >> n >> x1 >> y1 >> x2 >> y2;
	long long t, l = 0;
	long long r = std::max(
		(n - 1) * (x1 + y1) + x1,
		(n - 1) * (x2 + y2) + x2
    );
	while ((l + 1) < r) {
		long long m = l + (r - l) / 2;
		t = m / (x1 + y1);
		long long p1 = t + ((m - t * (x1 + y1)) >= x1);
		t = m / (x2 + y2);
		long long p2 = t + ((m - t * (x2 + y2)) >= x2);
		if ((p1 + p2) >= n)
			r = m;
		else
			l = m;
	}
	std::cout << r << std::endl;
}
