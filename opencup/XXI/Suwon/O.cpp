#include <bits/stdc++.h>

using namespace std;

struct pt {
	long long x;
	long long y;
	bool used;
	pt() {
		x = 0;
		y = 0;
		used = false;
	}
};

long long dist(pt &l, pt &r) {
	long long res = (l.x - r.x) * (l.x - r.x) + (l.y - r.y) * (l.y - r.y);
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pt> nums(n);
	for(int i = 0; i < n; ++i){
		cin >> nums[i].x;
		cin >> nums[i].y;
		nums[i].used = false;
	}
	vector<pair<int, int> > answer(n/2);
	for (int step = 0; step < n/2; ++step) {
		long long minDist = LLONG_MAX;
		for (int i = 0; i < n; ++i) {
			if (nums[i].used == true ) {
				continue;
			}
			for (int j = i + 1; j < n; ++j) {
				if ( nums[j].used == true ) continue;
				minDist = min(minDist, dist(nums[i], nums[j]));
			}
		}
		bool ok = false;
		for (int i = 0; i < n; ++i) {
			if (ok) break;
			if (nums[i].used) continue;
			for (int j = i + 1; j < n; ++j) {
				if (nums[j].used) continue;
				if (dist(nums[i], nums[j]) == minDist) {
					nums[i].used = true;
					nums[j].used = true;
					answer[step] = make_pair(i + 1, j + 1);
					ok = true;
					break;
				}
			}
		}
	}
	sort(answer.begin(), answer.end());
	for (int i = 0; i < n/2; ++i) {
		cout << answer[i].first << " " << answer[i].second << "\n";
	}
}
