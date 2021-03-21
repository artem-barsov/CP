#include <bits/stdc++.h>

using namespace std;
using Graph = std::vector<std::vector<int> >;

int wb[2] = {0, 0};

void dfs(Graph& gra, int from, int u, bool color) {
    ++wb[color];
    for (int v : gra[u]) {
        if (v != from) dfs(gra, u, v, !color);
    }
}

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    Graph gra(n);
    for (size_t i = 0; i < n-1; i++) {
        int u, v;
        std::cin >> u >> v;
        --u; --v;
        gra[u].push_back(v);
        gra[v].push_back(u);
    }
    dfs(gra, -1, 0, 0);
    std::cout << wb[0] *1ull* wb[1] - n + 1ull << '\n';
}
