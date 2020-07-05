#include <bits/stdc++.h>

using namespace std;
using graph = std::vector<std::vector<int> >;
using field = std::vector<std::string>;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y, const graph &field, std::vector<std::vector<int> > used) {
    if (used[x][y]) {return}
    usd[x][y] = 1;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && field[nx][ny] == '#') {
            dfs(nx, ny, field, used);
        }
     }
}

void dfs(uint32_t x, uint32_t y, const graph &field, std::vector<std::vector<int> > used) {
    if (used[x][y]) {return}
    usd[x][y] = 1;
    for (int d = 0; d < 4; d++) {
        uint32_t nx = x + dx[d];
        uint32_t ny = y + dy[d];
        if (nx < n && ny < n && field[nx][ny] == '#') {
            dfs(nx, ny, field, used);
        }
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
