#include <bits/stdc++.h>

using namespace std;

#define STAR false
#define CELL true

bool checkDegree(vector<vector<bool> > &v1, vector<vector<bool>> &v2) {
	int n = v1.size();
	bool ok = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (v1[i][j] != v2[i][j]) {
				ok = false;
			}
		}
	}
	if (ok) return true;
	ok = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (v1[i][j] != v2[j][n-1-i]) {
				ok = false;
			}
		}
	}
	if (ok) return true;
	ok = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (v1[i][j] != v2[n-1-i][n-1-j]) {
				ok = false;
			}
		}
	}
	if (ok) return true;
	ok = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (v1[i][j] != v2[n - 1 - j][i]) {
				ok = false;
			}
		}
	}
	return ok;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<bool> > nums(n, vector<bool>(n));
	vector<vector<bool> > copy(n, vector<bool>(n));
	vector<vector<bool> > templ(n, vector<bool>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			char x;
			cin >> x;
			if (x == '*')
				nums[i][j] = STAR;
			else
				nums[i][j] = CELL;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			char x;
			cin >> x;
			if (x == '*')
				templ[i][j] = STAR;
			else
				templ[i][j] = CELL;
		}
	}
	if (checkDegree(nums, templ)) {
		cout << "YES\n";
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			copy[i][j] = nums[i][n-1-j];
		}
	}
	if (checkDegree(copy, templ)) {
		cout << "YES\n";
		return 0;
	}
	for (int i = 0; i < n/2; ++i) {
		copy[i].swap(copy[n - 1 - i]);
	}
	if (checkDegree(copy, templ)) {
		cout << "YES\n";
		return 0;
	}
	for (int i = 0; i < n/2; ++i) {
		nums[i].swap(nums[n-1-i]);
	}
	if (checkDegree(nums, templ)) {
		cout << "YES\n";
		return 0;
	}
	cout << "NO\n";
}
