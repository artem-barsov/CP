#include <bits/stdc++.h>

using namespace std;

int fact(int x) {
	int res = 1;
	for (int i = 2; i <= x; ++i)
		res *= i;
	return res;
}

int main() {
	int k;
	double a, b, c, d = 1.0, answer;
	cin >> a >> b >> c;
	k = (c + 4.0) / 5.0;
	if (b >= k) {
		for (int i = 0; i < k; i++) {
			d = d * b / a;
			b--;
			a--;
		}
		answer = 1 - d;
		cout << setprecision(9) << answer << '\n';
	}
	else
		cout << "1" << '\n';
}
