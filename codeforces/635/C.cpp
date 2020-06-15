#include <bits/stdc++.h>

using namespace std;

struct Stadt {
    std::vector<int> nachbarn;
    int depth = 0, unter = 0, gluck = 0;
};

void dfs(int u, std::vector<Stadt> &stadte, std::vector<bool> &used, int depth) {
    used[u] = true;
    stadte[u].depth = depth;
    for (int v : stadte[u].nachbarn) {
        if (!used[v]) {
            dfs(v, stadte, used, depth+1);
            stadte[u].unter += stadte[v].unter;
        }
    }
    stadte[u].unter++;
    stadte[u].gluck = stadte[u].depth - stadte[u].unter + 1;
}

bool operator < (const Stadt & lhs, const Stadt & rhs) {
    return lhs.gluck > rhs.gluck;
}

int main(int argc, char const *argv[]) {
    int n, k;
    std::cin >> n >> k;
    std::vector<Stadt> stadte(n);
    std::vector<bool> used(n, false);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        stadte[u].nachbarn.push_back(v);
        stadte[v].nachbarn.push_back(u);
    }
    dfs(0, stadte, used, 0);
    partial_sort(stadte.begin(), stadte.begin()+k, stadte.end());
    unsigned long long sum = 0;
    for (int i = 0; i < k; i++) sum += stadte[i].gluck;
    std::cout << sum << '\n';
}
