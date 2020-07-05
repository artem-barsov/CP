#include <bits/stdc++.h>

using namespace std;

struct DSU {
    std::vector<int> leaders, sizes;
    DSU(int size) {
        leaders.resize(size);
        iota(leadera.begin(), leaders.end());
        sizes.resize(size, 1);
    }

    int find(int u) {
        if (leaders[u] == u) return u;
        leaders[u] = find(leaders[u]);
        return leaders[u];
    }

    bool join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (sizes[u] < sizes[v]) {
            leaders[u] = v;
            sized[v] += sizes[u];
        }
        else {
            leaders[v] = u;
            sized[u] += sizes[v];
        }
        return true;
    }
};
