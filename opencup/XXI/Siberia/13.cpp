#include <bits/stdc++.h>

using namespace std;

int poisonGlobal = 0;
set<int> poisonVertex;
vector<vector<int> > grev;

void dfs(int idx) {
	if (poisonVertex.find(idx) == poisonVertex.end()) {
		++poisonGlobal;
		poisonVertex.insert(idx);
	}
	for (auto &x: grev[idx]) {
		if (poisonVertex.find(x) == poisonVertex.end()) {
			dfs(x);
		}
	}
	grev[idx].clear();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k, m;
	cin >> n >> k >> m;
	grev.resize(n);
	poisonGlobal = k;
	int value;
	for(int i = 0; i < k; ++i){
		cin >> value;
		--value;
		poisonVertex.insert(value);
	}
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		--a;
		--b;
		// a --> b
		grev[b].push_back(a);
		if (poisonVertex.find(b) != poisonVertex.end()) {
			dfs(b);
		}
		cout << poisonGlobal << "\n";
	}
}
