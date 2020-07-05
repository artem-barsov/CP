#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

struct DSU {
    std::vector<int> leaders;
    std::vector<int> sizes;
    DSU(int size) {
        leaders.resize(size);
        iota(leaders.begin(), leaders.end(), 0);
        sizes.resize(size, 1);
    }
    int find(int u) {
        if (leaders[u] == u) return u;
        leaders[u] = find(leaders[u]);
        return leaders[u];
    }
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (sizes[u] < sizes[v]) {
                leaders[u] = v;
                sizes[v] += sizes[u];
            }
            else {
                leaders[v] = u;
                sizes[u] += sizes[v];
            }
        }
        std::cout << max(sizes[u], sizes[v]) << '\n';
    }
};

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        dsu.join(u-1, v-1);
    }
}
