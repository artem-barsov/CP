#include <bits/stdc++.h>

using namespace std;

#define all(a) a.begin(), a.end()

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int> > nums(m);
	for (int i = 0; i < m; ++i) {
		cin >> nums[i].first;
		nums[i].second = i + 1;
	}
	sort(all(nums));
	if ( nums[m - 1].first >= n ) {
		cout << 1 << "\n";
		cout << nums[m - 1].second << "\n";
		return 0;
	}
	int sum = 0;
	vector<int> answer;
	answer.push_back(nums[m - 1].second);
	sum += nums[m - 1].first;

	for (int i = m - 2; i >= 0; --i) {
		answer.push_back(nums[i].second);
		sum += nums[i].first;
		if (( sum - 2 * ( answer.size() - 1) ) >= n) {
			n = 0;
			break;
		}
	}
	if ( n != 0 ) {
		cout << "Epic fail\n";
		return 0;
	}
	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); ++i) {
		cout << answer[i] << " ";
	}
	cout << "\n";
}
