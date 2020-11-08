#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int m;
		cin >> m;
		int answer = 0;
		int cnt = 0;
		int in, out;
		for (int i = 0; i < m; ++i) {
			cin >> in >> out;
			cnt += (out - in);
			answer = max(answer, cnt);
		}
		cout << answer << "\n";
	}
}
