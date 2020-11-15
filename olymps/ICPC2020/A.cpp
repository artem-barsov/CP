#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	int c, d;
	cin >> c >> d;
	int answer = 0;
	if (a * c <= 0 || b * d <= 0) {
		answer += 1;
	}
	cout << answer << "\n";
}
