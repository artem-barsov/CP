#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	int n = s.size();

	set<char> letters;
	for (int i = 0; i < n; ++i) {
		letters.insert(s[i]);
	}
	if ( letters.size() <= 2) {
		cout << 0 << "\n";
		return 0;
	}

	vector<int> dict(26, 0);
	for (int i = 0; i < n; ++i) {
		dict[s[i] - 'a']++;
	}
	sort(dict.begin(), dict.end());
	long long answer = n - dict[25] - dict[24];
	cout << answer << "\n";
}
