#include <bits/stdc++.h>

using namespace std;
using graph = std::vector<std::vector<int> >;

int num = 0;

void dfs(int u, const graph &gr, std::vector<int> &used, std::vector<int> &besuch) {
    if (used[u]) return;
    used[u] = 1;
    besuch[u] = num++;
    for (int v : gr[u]) {
        dfs(v, gr, used, besuch);
    }
}

int main(int argc, char const *argv[]) {
    int n, m, k;
    std::cin >> n >> m >> k;
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
    std::vector<int> besuch(n, -1);
    dfs(k-1, gr, used, besuch);
    for (int i = 0; i < n; i++) { std::cout << besuch[i] << ' '; }
}
