#include <bits/stdc++.h>

using namespace std;
using graph = std::vector<std::vector<int> >;

int dfs(int u, const graph &gr, std::vector<int> &used) { // count of vertex
    if (used[u]) return 0;
    used[u] = 1;
    int count = 1;
    for (int v : gr[u]) {
        count += dfs(v, gr, used);
    }
    return count;
}

void bfs(int s, const graph &gr, std::vector<int> &lvls) {
    lvls.assign(gr.size(), -1);
    lvls[s] = 0;
    std::queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : gr[u]) {
            if (lvls[v] != -1) continue;
            lvls[v] = lvls[u] + 1;
            q.push(v);
        }
    }
}

std::vector<int> get_path(int s, int f, const graph &gr) {
    std::vector<int> lvls;
    bfs(f, gr, lvls);
    std::vector<int> path;
    path.push_back(s);
    while (path.back() != f) {
        int lvl = lvls[path.back()];
        for (int prev : gr[path.back()]) {
            if (lvls[prev] == lvl-1) {
                path.push_back(prev);
                break;
            }
        }
    }
    return path;
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
