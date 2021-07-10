#include <bits/stdc++.h>

using namespace std;
using Graph = std::vector<std::vector<int> >;

void dfs(Graph& gra, std::vector<int>& clr, int u) {
    for (int v : gra[u]) {
        if (clr[v] != -1) continue;
        clr[v] = !clr[u];
        dfs(gra, clr, v);
    }
}

int main(int argc, char const *argv[]) {
    int n, q;
    std::cin >> n >> q;
    Graph gra(n);
    for (size_t i = 0; i < n-1; i++) {
        int a, b;
        std::cin >> a >> b;
        a--; b--;
        gra[a].push_back(b);
        gra[b].push_back(a);
    }
    std::vector<int> clr(n, -1);
    clr[0] = 0;
    dfs(gra, clr, 0);
    for (size_t i = 0; i < q; i++) {
        int c, d;
        std::cin >> c >> d;
        c--; d--;
        std::cout << ((clr[c] == clr[d]) ? "Town" : "Road") << '\n';
    }
}
