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
    int n, m, x, y;
    std::cin >> n >> m;
    graph gr(n*n);
    std::string prevs, s;
    for (int i = 0; i < n; i++) {
        prevs = s;
        std::cin >> s;
        for (int j = 0; j < m; j++) {
            if ((j < m-1) && (s[j+1] == '.')) gr[i*m+j].push_back(i*m+j + 1);
            if ((j > 0) && (s[j-1] == '.')) gr[i*m+j].push_back(i*m+j + 1);
            if ((i > 0) && (prevs[j] == '.') && (s[j] == '.')) {
                gr[i*m+j].push_back((i-1)*m+j);
                gr[(i-1)*m+j].push_back(i*m+j);
            }
        }
    }
    std::vector<int> used(n);
    std::vector<int> weg(n, -1);
    int k = (x-1)*m + y-1;
    bfs(k, gr, weg);

    for (int i = 0; i < n; i++) { std::cout << weg[i] << ' '; }
}
