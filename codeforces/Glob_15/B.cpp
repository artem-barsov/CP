#include <bits/stdc++.h>

using namespace std;

bool beats(std::vector<int[5]>& r, int p1, int p2) {
    int c = 0;
    for (int i = 0; i < 5; i++) {
        c += r[p1][i] < r[p2][i];
    }
    return c >= 3;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int[5]> r(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            std::cin >> r[i][j];
        }
    }
    int w = 0;
    for (int i = 1; i < n; i++) {
        if (beats(r, i, w)) w = i;
    }
    for (int i = 0; i < w; i++) {
        if (beats(r, i, w)) {
            std::cout << -1 << '\n';
            return;
        }
    }
    std::cout << w + 1 << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
