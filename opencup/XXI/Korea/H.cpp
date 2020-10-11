#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n, k;
	cin >> n >> k;
	vector<long long> cost(6, 0);
	vector<long long> nums(n);
	for(int i = 0; i < 6; ++i)
		cin >> cost[i];
	for(int i = 0; i < n; ++i)
		cin >> nums[i];
	long long answer = 0;
	int bf = 0;
	long long copyK = k;
    while (bf < (1 << 6)) {
        bitset<6> bs(bf);
		k = copyK;
		long long cnt = 0;
		for(int i = 0; i < n; ++i){
			long long type = nums[i] - 1;
			if( bs[type] == 1){
				if( k >= cost[type] ){
					++cnt;
					k -= cost[type];
				}
			}
		}
		answer = max(answer, cnt);
		++bf;
	}
	cout << answer << "\n";
}
