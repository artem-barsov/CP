#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<string> nums(n);
	string s;
	for(int i = 0; i < n; ++i){
		cin >> s;
		reverse(s.begin(), s.end());
		nums[i] = s;
	}
	sort(nums.begin(), nums.end());
	for(int i = 0; i < n; ++i){
		cout << nums[i] << "\n";
	}
}
