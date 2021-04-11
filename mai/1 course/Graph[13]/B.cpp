#include <bits/stdc++.h>

using namespace std;
using graph = std::vector<std::vector<int> >;

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
    std::vector<int> weg(n, -1);
    bfs(k-1, gr, weg);

    for (int i = 0; i < n; i++) { std::cout << weg[i] << ' '; }
}
