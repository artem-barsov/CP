#include <bits/stdc++.h>

using namespace std;
using graph = std::vector<std::vector<int> >;

int dfs(int u, int p, const graph &gr, std::vector<int> &color, std::vector<int> &cycle) {
    if (color[u] == 2) return 0;
    if (color[u] == 1) {
        cycle.push_back(u);
        return 1;
    }
    color[u] = 1;
    for (int v : gr[u]) {
        if (v == p) continue;
        int result = dfs(v, u, gr, color, cycle);
        if (result == 1) {
            if (u == cycle[0]) {
                return 2;
            } else {
                cycle.push_back(u);
                return 1;
            }
        }
        if (result == 2) {
            return 2;
        }
    }
    color[u] = 2;
    return 0;
}

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    graph gr(n);
    for (int i = 0; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u -= 1;
        v -= 1;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    std::vector<int> color(n);
    std::vector<int> cycle;
    dfs(0, 0, gr, color, cycle) << '\n';
    sort(cycle.begin(), cycle.end());
    for (int i = 0; i < cycle.size(); i++) {
        std::cout << cycle[i]+1 << ' ';
    }
}
