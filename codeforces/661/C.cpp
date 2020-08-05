#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> w(n);
    for (int i = 0; i < n; i++) std::cin >> w[i];
    set<int> sums;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            sums.insert(w[i] + w[j]);
        }
    }
    int max_c = 0;
    for (auto & sum : sums) {
        std::vector<bool> used(n);
        // printf("sum=%d:\n", sum);
        int c = 0;
        for (int i = 0; i < n-1; i++) {
            if (used[i]) continue;
            for (int j = i+1; j < n; j++) {
                if (used[j]) continue;
                if (w[i] + w[j] == sum) {
                    c++;
                    // printf("c=%d i=%d j=%d w[i]=%d w[j]=%d\n", c, i, j, w[i], w[j]);
                    used[i] = used[j] = true;
                    break;
                }
            }
        }
        max_c = max(max_c, c);
    }
    std::cout << max_c << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
