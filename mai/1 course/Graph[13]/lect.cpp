#include <bits/stdc++.h>

using namespace std;
using graph = std::vector<std::vector<int> >;

void dfs(int u, const graph &gr, std::vector<int> &used) {
    if (used[u]) return;
    used[u] = 1;
    for (int v : gr[u]) {
        dfs(v, gr, used);
    }
}

int main(int argc, char const *argv[]) {
    int n, m;
    std::cin >> n >> m;
    graph gr(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u -= 1;
        v -= 1;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    std::vector<int> used(n);
    int ccs = 0; // conected components
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i, gr, used);
            ccs += 1;
        }
    }
}
