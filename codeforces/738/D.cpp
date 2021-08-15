#include <bits/stdc++.h>

using namespace std;

struct DSU {
    std::vector<int> parent, rank;
    DSU(int n)
    : parent(std::vector<int>(n)), rank(std::vector<int>(n, 0)) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int v) {
    	if (v == parent[v]) return v;
    	return parent[v] = find(parent[v]);
    }
    void join(int a, int b) {
    	a = find(a);
    	b = find(b);
    	if (a != b) {
    		if (rank[a] < rank[b]) swap(a, b);
    		parent[b] = a;
    		if (rank[a] == rank[b]) ++rank[a];
    	}
    }
};

int main(int argc, char const *argv[]) {
    int n, m1, m2;
    std::cin >> n >> m1 >> m2;
    DSU f1(n), f2(n);
    for (int i = 0; i < m1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        f1.join(u, v);
    }
    for (int i = 0; i < m2; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        f2.join(u, v);
    }
    std::queue<std::pair<int, int> > qout;
    for (int u = 0; u < n-1; u++) {
        for (int v = u+1; v < n; v++) {
            if (f1.find(u) == f1.find(v)) continue;
            if (f2.find(u) == f2.find(v)) continue;
            f1.join(u, v);
            f2.join(u, v);
            qout.push({u, v});
        }
    }
    std::cout << qout.size() << '\n';
    while (!qout.empty()) {
        auto& [u, v] = qout.front();
        std::cout << u+1 << ' ' << v+1 << '\n';
        qout.pop();
    }
}
