#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, m, q;
    std::cin >> n >> m;
    std::vector<int> out(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        out[min(u, v)]++;
    }
    int surv = 0;
    for (auto& x : out) surv += !x;
    std::cin >> q;
    while (q--) {
        int p;
        std::cin >> p;
        if (p == 1) {
            int u, v;
            std::cin >> u >> v;
            u--; v--;
            surv -= !out[min(u, v)]++;
        } else if (p == 2) {
            int u, v;
            std::cin >> u >> v;
            u--; v--;
            surv += !--out[min(u, v)];
        } else {
            std::cout << surv << '\n';
        }
    }
}
