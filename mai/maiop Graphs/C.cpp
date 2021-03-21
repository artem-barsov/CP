#include <bits/stdc++.h>

using namespace std;

using Graph = std::vector<std::vector<int> >;

bool is_leaf(Graph& gra, int u) {
    return (u != 0) && (gra[u].size() == 1);
}

bool is_branch(Graph& gra, int u) {
    return (u != 0) && (gra[u].size() == 2) && (is_leaf(gra, gra[u][0]) || is_leaf(gra, gra[u][1]));
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
    int c = 0;
    for (size_t i = 0; i < n; i++) {
        c += is_branch(gra, i);
    }
    std::cout << c << '\n';
}
