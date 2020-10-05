#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	int n, w;
	cin >> n >> w;
	vector<set<int> > edge(n);
	for (int i = 0; i < w; ++i) {
		int p, q;
		cin >> p >> q;
		--p; --q;
		int from = min(p, q);
		int to = max(p, q);
		edge[from].insert(to);
		edge[to].insert(from);
	}
	bool safe = true;
	stack<pair<int, int> > wait;
	for (int i = 0; (i < n) && safe; ++i) {
		if (edge[i].empty()) continue;
		while (!wait.empty()) {
			pair<int, int> value = wait.top();
			if (value.second != i) break;
			wait.pop();
		}
		if (wait.empty()) {
			for (auto it = edge[i].rbegin(); it != edge[i].rend(); ++it) {
				if (*it > i) wait.push(make_pair(i, *it));
			}
		}
		else {
			pair<int, int> value = wait.top();
			for (auto it = edge[i].rbegin(); it != edge[i].rend(); ++it) {
				if (*it > value.second) {
					safe = false;
					break;
				}
				if (*it > i)
					wait.push(make_pair(i, *it));
			}
		}
	}
    std::cout << (safe ? "Safe" : "Unsafe") << '\n';
}
