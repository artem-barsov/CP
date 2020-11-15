#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> nums = {2, 3, 5, 7, 23, 37, 53, 73, 373};
	long long left, right;
	cin >> left >> right;
	int cnt = 0;
	for(int i = 0; i < nums.size(); ++i){
		if((nums[i] >= left) && (nums[i] <= right)){
			++cnt;
		}
	}
	cout << cnt << "\n";
}
