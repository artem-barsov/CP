#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
const ull INF = INT_MAX;

int main(int argc, char const *argv[]) {
    ull n, m;
    std::cin >> n >> m;
    std::vector<std::vector<ull> > gra(n, std::vector<ull>(n, INF));
    for (ull i = 0; i < m; i++) {
        ull a, b, c;
        std::cin >> a >> b >> c;
        a--; b--;
        gra[a][b] = c;
    }
    for (ull i = 0; i < n; i++) gra[i][i] = 0;
    unsigned long long ans = 0;
    for (ull k = 0; k < n; k++) {
        for (ull i = 0; i < n; i++) {
            for (ull j = 0; j < n; j++) {
                if (gra[i][j] < INF || (gra[i][k] < INF && gra[k][j] < INF)) {
                    gra[i][j] = min(gra[i][j], gra[i][k] +0ull+ gra[k][j]);
                    ans += gra[i][j];
                }
            }
        }
    }
    std::cout << ans << '\n';
}
