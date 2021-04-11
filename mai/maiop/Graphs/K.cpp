#include <bits/stdc++.h>

using namespace std;
using Graph = std::vector<std::vector<int> >;

void dfs(Graph& gra, int u, std::vector<int>& wave, int depth) {
    if (wave.size() > depth) ++wave[depth];
    else wave.push_back(1);
    for (int v : gra[u]) {
        dfs(gra, v, wave, depth+1);
    }
}

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    Graph gra(n);
    for (size_t i = 1; i < n; i++) {
        int u;
        std::cin >> u;
        --u;
        gra[u].push_back(i);
    }
    std::vector<int> wave(1);
    dfs(gra, 0, wave, 0);
    int c = 0;
    for (int t : wave) c += t&1;
    std::cout << c << '\n';
}
