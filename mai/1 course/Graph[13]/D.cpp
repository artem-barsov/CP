#include <bits/stdc++.h>

using namespace std;
using graph = std::vector<std::vector<int> >;

void bfs(int s, int f, const graph &gr, std::vector<int> &lvls) {
    lvls[s] = 0;
    std::queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : gr[u]) {
            if (lvls[v] != -1) continue;
            lvls[v] = lvls[u] + 1;
            if (v == f) return;
            q.push(v);
        }
    }
}

int main(int argc, char const *argv[]) {
    int n, m, s, f;
    std::cin >> n >> m >> s >> f;
    s--, f--;
    graph gr(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    std::vector<int> lvls(n, -1);
    bfs(f, s, gr, lvls);
    int depth = lvls[s];
    if (depth == -1) {
        std::cout << -1 << '\n';
        return 0;
    }
    std::vector<int> path(1, s);
    while (path.back() != f) {
        int u = path.back();
        int lex_min = INT_MAX;
        for (int v : gr[u]) {
            if (lvls[v] == lvls[u]-1)
                lex_min = min(lex_min, v);
        }
        path.push_back(lex_min);
    }
    for (int pi : path) std::cout << pi+1 << ' ';
    std::cout << '\n';
}
