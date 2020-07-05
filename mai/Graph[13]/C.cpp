#include <bits/stdc++.h>

using namespace std;
using graph = std::vector<std::vector<int> >;
bool stop = false;
bool found = false;

void dfs(int s, int f, const graph &gr, std::vector<int> &used, std::stack<int> &weg) {
    // if (stop) return;
    if (used[s]) return;
    used[s] = 1;
    weg.push(s);
    if (s == f) {
        while (!weg.empty()) {
            std::cout << weg.top()+1 << ' ';
            weg.pop();
        }
        found = true;
        // stop = true;
        return;
    }
    for (int v : gr[s]) {
        dfs(v, f, gr, used, weg);
    }
    if (!weg.empty()) weg.pop();
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
    if (s == f) {
        std::cout << s << '\n';
        return 0;
    }
    std::vector<int> used(n);
    std::stack<int> weg;
    dfs(f-1, s-1, gr, used, weg);
    if (!found) {
        std::cout << -1 << '\n';
    }
}
