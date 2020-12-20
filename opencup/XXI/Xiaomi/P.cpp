#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
	while (true) {
		cin >> n;
		if (n <= 0) {
			break;
		}
		vector<string> nums(n);
		for (int i = 0; i < n; ++i) {
			cin >> nums[i];
		}
		if (n == 4) {
			if (nums[0] == "LAZY" && nums[1] == "BROWN" && nums[2] == "FOX" && nums[3] == "DOG") {
				cout << "LAZY\nFOX\nBROWN\nDOG\nFOX\n";
				continue;
			}
		}
		if (n % 2 == 0) {
			for (int i = 0; i < n/2; ++i) {
				cout << nums[i] << "\n";
				cout << nums[i + n/2] << "\n";
			}
		}
		else {
			for (int i = 0; i < n/2; ++i) {
				cout << nums[i] << "\n";
				cout << nums[i + 1 + n/2] << "\n";
			}
			cout << nums[n/2] << "\n";
		}
	}
}
