#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

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

using Graph = std::vector<std::vector<int> >;

void dfs(Graph& gra, std::vector<char>& used,
         DSU& forest, std::vector<int>& cnt, int u) {
    used[u] = true;
    for (int v : gra[u]) {
        if (used[v]) continue;
        dfs(gra, used, forest, cnt, v);
        forest.join(u, v);
        cnt[u] += cnt[v];
    }
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n, m;
    std::cin >> n >> m;
    Graph gra(n);
    std::vector<std::pair<int, int> > edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        edges[i] = { u, v };
        gra[u].push_back(v);
        gra[v].push_back(u);
    }
    std::vector<char> used(n, false);
    DSU forest(n);
    std::vector<int> tree_size(n);
    std::vector<int> cnt(n, 1);
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(gra, used, forest, cnt, i);
            tree_size[forest.find(i)] = cnt[i];
        }
    }
    int q;
    std::cin >> q;
    while (q--) {
        int edge;
        std::cin >> edge;
        auto [u, v] = edges[edge - 1];
        int x = min(cnt[u], cnt[v]);
        std::cout << x *1ull* (tree_size[forest.find(u)] - x) << '\n';
    }
}
