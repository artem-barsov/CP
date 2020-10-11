#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	int n, w ,d;
	cin >> n >> w >> d;
	vector<int> nums(41, 0);
	for(int i = 0; i < n; ++i){
		int value;
		cin >> value;
		nums[value]++;
	}
	int cnt = 0;
	bool ok = true;
	for (int i = 0; i <= 40; ++i) {
		if (nums[i] > d) ok = false;
		if (nums[i] != 0) ++cnt;
	}
	if (!ok || (cnt > w)) {
		cout << -1 << "\n";
		return 0;
	}
	for (int i = 1; i <= 40; ++i) {
        if (nums[i] != 0)
			std::cout << i << ' ';
    }
	cout << "\n";
	for (int i = 1; i <= 40; ++i) {
        if (nums[i] != 0)
			std::cout << nums[i] << ' ';
    }
	cout << "\n";
}
