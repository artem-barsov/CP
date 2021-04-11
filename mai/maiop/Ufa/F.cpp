#include <bits/stdc++.h>

using namespace std;

bool task(int i, int j, int k, vector<int> &nums) {
	if (nums[i] == 2) return false;
	if (nums[i] == 0 ) {
		if (nums[j] == 2) return false;
		if ((nums[j] == 0) && (nums[k] == 2)) return false;
		if ((nums[j] == 1) && (nums[k] == 0)) return false;
		if ((nums[j] == 1) && (nums[k] == 1)) {
			nums[j] = 0;
			nums[k] = 0;
		}
		else if ((nums[j] == 1) && (nums[k] == 2)) {
			nums[j] = 0;
			nums[k] = 1;
		}
		return true;
	}
	if (nums[i] == 1 ) {
		if (nums[j] == 0 ) return false;
		if ((nums[j] == 1) && (nums[k] == 2)) return false;
		if ((nums[j] == 2) && (nums[k] == 0)) return false;
		if ((nums[j] == 1) && (nums[k] == 1)) {
			nums[i] = 0;
			nums[j] = 0;
			nums[k] = 1;
		}
		else if ((nums[j] == 1) && (nums[k] == 0)) {
			nums[i] = 0;
			nums[j] = 0;
			nums[k] = 0;
		}
		else if ((nums[j] == 2) && (nums[k] == 1)) {
			nums[i] = 0;
			nums[j] = 0;
			nums[k] = 0;
		}
		else if ((nums[j] == 2) && (nums[k] == 2)) {
			nums[i] = 0;
			nums[j] = 0;
			nums[k] = 1;
		}
		return true;
	}
}

int main() {
    int n;
	cin >> n;
	vector<int> nums(n);
	vector<int> nums2(n);
	for(int i = 0; i < n; ++i) {
		cin >> nums[i];
		nums2[i] = nums[i];
	}
	if (n == 1) {
		cout << "Yes\n";
		return 0;
	}
	if (n == 2) {
		if ((nums[0] == 0) && (nums[1] == 2)) {
			cout << "No\n";
			return 0;
		}
		if ((nums[0] == 2) && (nums[1] == 0)) {
			cout << "No\n";
			return 0;
		}
		cout << "Yes\n";
		return 0;
	}
	bool answer = true;
	if (nums[0] == 0) {
		for (int i = 0; i < n - 2; ++i ) {
			if (!task(i, i + 1, i + 2, nums)) {
				answer = false;
				break;
			}
		}
	}
	else {
		for (int i = 0; i < n - 2; ++i ) {
			if (!task(i, i + 1, i + 2, nums)) {
				answer = false;
				break;
			}
		}
		if (!answer) {
			answer = true;
			nums2[0] -= 1;
			for (int i = 0; i < n - 2; ++i ) {
				if (!task(i, i + 1, i + 2, nums2)) {
					answer = false;
					break;
				}
			}
		}
	}
    std::cout << (answer ? "Yes" : "No") << '\n';
}
