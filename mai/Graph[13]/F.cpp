#include <bits/stdc++.h>

using namespace std;
using graph = std::vector<std::vector<int> >;

void bfs(int s, const graph &gr, std::vector<int> &lvls) {
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
    int n, m, x, y;
    std::cin >> n >> m;
    graph gr(n * m);
    std::string prevs, s;
    for (int i = 0; i < n; i++) {
        prevs = s;
        std::cin >> s;
        for (int j = 0; j < m; j++) {
            if ((j < m-1) && (s[j] == '.') && (s[j+1] == '.')) {
                int u = i*m + j, v = i*m + j + 1;
                gr[u].push_back(v);
                gr[v].push_back(u);
            }
            if ((i > 0) && (prevs[j] == '.') && (s[j] == '.')) {
                int u = i*m + j, v = (i-1)*m + j;
                gr[u].push_back(v);
                gr[v].push_back(u);
            }
        }
    }
    std::cin >> x >> y;
    std::vector<int> lvls(n * m, -1);
    bfs((x-1)*m + y-1, gr, lvls);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            std::cout << lvls[i*m + j] << ' ';
        std::cout << '\n';
    }

}
