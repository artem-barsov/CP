#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

int main() {
	int n = 0;
	std::cin >> n;
	int d = 0;
	std::cin >> d;
	std::vector<int> x(n);
	std::vector<int> y(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> x[i];
		std::cin >> y[i];
	}
	std::vector<std::vector<bool>> m(
		n, std::vector<bool>(n, false)
	);
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			double x1 = x[i];
			double x2 = x[j];
			double y1 = y[i];
			double y2 = y[j];
			double dist = std::sqrt(
				(x1 - x2) * (x1 - x2) +
				(y1 - y2) * (y1 - y2)
			);
			m[i][j] = (dist <= (double)d);
			m[j][i] = (dist <= (double)d);
		}
	}
	std::vector<bool> h(n, false);
	std::queue<int> q;
	q.push(0);
	h[0] = true;
	while (!q.empty()) {
		int p = q.front();
		if (p == (n - 1)) {
			break;
		}
		q.pop();
		for (int a = 0; a < n; ++a) {
			if (m[p][a] && !h[a]) {
				q.push(a);
				h[a] = true;
			}
		}
	}
	if (q.empty())
		std::cout << "n" << std::endl;
	else
		std::cout << "y" << std::endl;
}
