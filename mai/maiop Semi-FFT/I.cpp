#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		string a, b;
		cin >> n >> m >> k;
		cin >> a >> b;
		int entry[26][26];
		for (int i = 0; i < 26; ++i){
			for (int j = 0; j < 26; ++j){
				entry[i][j] = 0;
			}
		}
		for (int i = 0; i < a.size() - k + 1; ++i) {
			entry[a[i] - 'a'][a[i + k - 1] - 'a']++;
		}
		vector<int> nums(26);
		for (int i = 0; i < b.size(); ++i) {
			++nums[b[i] - 'a'];
		}
		long long answer = 0;
		for (int i = 0; i < b.size(); ++i) {
			int left = b[i] - 'a';
			for (int j = 0; j < 26; ++j) {
				if ( nums[j] > 0) {
					answer = answer + nums[j] * (entry[left][j] > 0);
				}
			}
			--nums[b[i] - 'a'];
		}
		cout << answer << "\n";
	}
}
