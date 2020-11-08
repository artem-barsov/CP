#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<long long> nums(n);
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
	long long answer = LLONG_MAX;
	long long tmp;
	for (int i = 0; i < n; ++i) {
		tmp = nums[i] + nums[nums.size()-1-i];
		answer = min(answer, tmp);
	}
	cout << answer << "\n";
}
