#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

struct DSU {
    std::vector<int> leaders, sizes, min_id, max_id;
    std::vector<long long> sum_id;
    DSU(int size) {
        leaders.resize(size);
        sizes.resize(size, 1);
        sum_id.resize(size);
        min_id.resize(size);
        max_id.resize(size);
        for (int i = 0; i < size; i++)
            sum_id[i] = 1 + (leaders[i] = min_id[i] = max_id[i] = i);
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
                std::cout << (sum_id[v] += sum_id[u]) << ' '
                << (min_id[v] = min(min_id[v], min_id[u]))+1 << ' '
                << (max_id[v] = max(max_id[v], max_id[u]))+1 << '\n';
            }
            else {
                leaders[v] = u;
                sizes[u] += sizes[v];
                std::cout << (sum_id[u] += sum_id[v]) << ' '
                << (min_id[u] = min(min_id[u], min_id[v]))+1<< ' '
                << (max_id[u] = max(max_id[u], max_id[v]))+1<< '\n';
            }
        }
        else std::cout << sum_id[u] << ' ' << min_id[u]+1 << ' ' << max_id[u]+1 << '\n';
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
