#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

ll min_hamilton(std::vector<std::vector<int> >& gra, std::vector<int>& path) {
    const int n = gra.size();
    std::vector<std::vector<ll> > dp(1<<n, std::vector<ll>(n, LONG_LONG_MAX));
    std::vector<std::vector<std::pair<int, int> > >
        dp_path(1<<n, std::vector<std::pair<int, int> >(n));
    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = 0;
        dp_path[1 << i][i] = { 0, -1 };
    }
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int u = 0; u < n; u++) {
            if (!((mask>>u)&1)) continue;
            if (dp[mask][u] < LONG_LONG_MAX) {
                for (int v = 0; v < n; v++) {
                    if ((mask>>v)&1) continue;
                    if (dp[mask | (1<<v)][v] > dp[mask][u] + gra[u][v]) {
                        dp[mask | (1<<v)][v] = dp[mask][u] + gra[u][v];
                        dp_path[mask | (1<<v)][v] = { mask, u };
                    }
                }
            }
        }
    }
    int nmask = (1 << n) - 1;
    int nxt = 0;
    ll ret = dp[nmask][nxt];
    for (int i = 0; i < n; i++) {
        if (ret > dp[(1 << n) - 1][i]) {
            ret = dp[(1 << n) - 1][i];
            nxt = i;
        }
    }
    while (nmask) {
        path.push_back(nxt);
        std::tie(nmask, nxt) = dp_path[nmask][nxt];
    }
    return ret;
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n;
    std::cin >> n;
    std::vector<std::vector<int> > gra(n, std::vector<int>(n));
    for (auto& u : gra)
        for (auto& uv : u)
            std::cin >> uv;
    std::vector<int> path;
    std::cout << min_hamilton(gra, path) << '\n';
    for (int u : path) std::cout << u + 1 << ' ';
    std::cout << '\n';
}
