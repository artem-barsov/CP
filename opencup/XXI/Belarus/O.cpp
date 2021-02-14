#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
using namespace std;
int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>> v(m, vector<int>(n));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			char d;
			cin >> d;
			v[i][j] = d - '0';
		}
	}
	int answer1 = 0, answer2 = 0, current, x, y;
	queue<tuple<int, int>> q;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (v[i][j] != 1) {
				continue;
			}
			v[i][j] = 2;
			q.push(make_tuple(i, j));
			current = 1;
			++answer2;
			while (!q.empty()) {
				x = get<1>(q.front());
				y = get<0>(q.front());
				q.pop();
				if (y + 1 < m && v[y + 1][x] == 1) {
					v[y + 1][x] = 2;
					q.push(make_pair(y + 1, x));
					++current;
				}
				if (y - 1 > -1 && v[y - 1][x] == 1) {
					v[y - 1][x] = 2;
					q.push(make_pair(y - 1, x));
					++current;
				}
				if (x + 1 < n && v[y][x + 1] == 1) {
					v[y][x + 1] = 2;
					q.push(make_pair(y, x + 1));
					++current;
				}
				if (x - 1 > -1 && v[y][x - 1] == 1) {
					v[y][x - 1] = 2;
					q.push(make_pair(y, x - 1));
					++current;
				}
				answer1 = max(answer1, current);
			}
		}
	}
	cout << answer2 << " " << answer1 << endl;
}
