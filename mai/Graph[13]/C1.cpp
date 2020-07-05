#include <bits/stdc++.h>

using namespace std;
using graph = std::vector<std::vector<int> >;

bool dfs(int s, int f, const graph &gr, std::vector<int> &used, std::vector<int> &weg) {
    if (used[s]) return false;
    used[s] = 1;
    weg.push_back(s);
    if (s == f) {
        return true;
    }
    for (int v : gr[s]) {
        if (dfs(v, f, gr, used, weg)) return true;
    }
    weg.pop_back();
    return false;
}

int main(int argc, char const *argv[]) {
    int n, m, s, f;
    std::cin >> n >> m >> s >> f;
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
    std::vector<int> weg;
    if (dfs(s-1, f-1, gr, used, weg)) {
        for (int i = 0; i < weg.size(); i++) {
            std::cout << weg[i]+1 << ' ';
        }
    }
    else std::cout << -1 << '\n';
}
