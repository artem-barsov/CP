#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> v(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}
	vector<vector<int>> d(m + 1,
		vector<int>(k + 1, 0));
	vector<vector<int>> r(m + 1,
		vector<int>(k + 1, 0));
	int found = 0;
	int i_max = 0;
	int j_max = 0;
	for (int j = 0; j <= k; ++j) {
		for (int i = 0; i <= m; ++i) {
			if ((2 * j + i) > n) continue;
			int virs = v[2 * j + i];
			if (i - 1 >= 0) {
				if (d[i][j] < (d[i - 1][j] + virs)) {
					d[i][j] = (d[i - 1][j] + virs);
					r[i][j] = 1;
				}
			}
			if (j - 1 >= 0) {
				if (d[i][j] < (d[i][j - 1] + virs)) {
					d[i][j] = (d[i][j - 1] + virs);
					r[i][j] = 2;
				}
			}
			if (d[i][j] > found) {
				i_max = i;
				j_max = j;
				found = d[i][j];
			}
		}
	}
	vector<int> answer;
	while (r[i_max][j_max] != 0) {
		answer.push_back(2 * j_max + i_max);
		if (r[i_max][j_max] == 1) {
			i_max -= 1; continue;
		}
		if (r[i_max][j_max] == 2) {
			j_max -= 1; continue;
		}
	}
	answer.push_back(0);
	n = answer.size();
	cout <<  found << endl;
	for (int i = 0; i < n; ++i) {
		cout << answer[n - i - 1] << " ";
	}
}
