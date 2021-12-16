#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    if (n & 1) {
        int a = (n - 1) / 2;
        if (a & 1)
            std::cout << a + 2 << ' ' << a - 2 << ' ' << 1 << '\n';
        else
            std::cout << a + 1 << ' ' << a - 1 << ' ' << 1 << '\n';
    }
    else
        std::cout << n / 2 << ' ' << n / 2 - 1 << ' ' << 1 << '\n';
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    std::cin >> t;
    while (t--) solve();
    // int n;
    // std::cin >> n;
    // for (int i = 1; i < n; i++) {
    //     for (int j = 1; j < n; j++) {
    //         for (int k = 1; k < n; k++) {
    //             if (i != j && j != k && i != k
    //             && i + j + k == n && gcd(i, j) == k) {
    //                 printf("%d %d %d\n", i, j, k);
    //             }
    //         }
    //     }
    // }
}
