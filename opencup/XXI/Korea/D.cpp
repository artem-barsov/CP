#include <bits/stdc++.h>

using namespace std;

long long idx(long long n){
	return n * (n - 1) / 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	cin >> n;
	long long m = n * (n - 1) / 2;
	vector<long long> nums(m);
	for(int i = 0; i < m; ++i)
	    cin >> nums[i];
	sort(all(nums));
	long long minAnswer = 0;
	for(int i = 0; i < n - 1; ++i)
		minAnswer += nums[i];
	long long maxAnswer = 0;
	for(int i = 1; i <= n -1; ++i)
		maxAnswer += nums[idx(i)];
	cout << minAnswer << " " << maxAnswer << "\n";
	return 0;
}
