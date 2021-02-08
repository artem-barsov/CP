#include <bits/stdc++.h>

using namespace std;

long long answer = 0;

void task(string s) {
	if (s.length() <= 1) {
		return;
	}
	answer += 1;
	long long newNum = 1;
	for (int i = 0; i < s.size(); ++i) {
		newNum *= (s[i] - '0');
	}
	string tmp = to_string(newNum);
	task(tmp);
}

int main() {
	string s;
	cin >> s;
	answer = 0;
	task(s);
	cout << answer << "\n";
}
