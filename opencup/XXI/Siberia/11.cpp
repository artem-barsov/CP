#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	vector<string> nums;
	set<string> po;
	map<string, int> mp;
	for(int i = 0; i < n; ++i){
		cin >> s;
		int idx = 0;
		for (int j = s.size() - 1; j >= 0 ; --j) {
			if (s[j] == '.' ) {
				idx = j;
				break;
			}
		}
		string res = s.substr(idx + 1, s.size());
		if (po.find(res) == po.end()) {
			po.insert(res);
			nums.push_back(res);
		}
		mp[res]++;
	}
	for (int i = 0; i < nums.size(); ++i) {
		cout << nums[i] << ": " << mp[nums[i]] << "\n";
	}
}
