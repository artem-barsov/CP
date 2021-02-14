#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

using Graph = std::vector<std::vector<int> >;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    Graph gra(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        --u; --v;
        gra[u].push_back(v);
        gra[v].push_back(u);
    }
    std::vector<int> color(n, -1);
    int sum_x = 0;
    for (int start = 0; start < n; start++) {
        if (color[start] == -1) {
            int x = 0, c = 1;
            queue<int> q;
            q.push(start);
            color[start] = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : gra[u]) {
                    if (color[v] == color[u]) {
                        std::cout << -1 << '\n';
                        return 0;
                    }
                    if (color[v] != -1) {
                        continue;
                    }
                    color[v] = !color[u];
                    x += color[v];
                    q.push(v);
                    ++c;
                }
            }
            sum_x += min(x, c-x);
        }
    }
    std::cout << sum_x << '\n';
}
