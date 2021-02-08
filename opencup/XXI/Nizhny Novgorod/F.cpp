#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<long long> first(3);
	vector<long long> second(3);
	cin >> first[0] >> first[1] >> first[2];
	cin >> second[0] >> second[1] >> second[2];
	sort(first.begin(), first.end());
	sort(second.begin(), second.end());

	bool ok1 = false;
	if ((first[0] * first[0]) + (first[1] * first[1]) == (first[2] * first[2])) {
		ok1 = true;
	}

	bool ok2 = false;
	if ((second[0] * second[0]) + (second[1] * second[1]) == (second[2] * second[2])) {
		ok2 = true;
	}

	bool ok3 = true;
	for (int i = 0; i < 3; ++i) {
		if ( first[i] != second[i]) {
			ok3 = false;
		}
	}
    std::cout << (ok1 && ok2 && ok3 ? 1 : 0) << '\n';
}
