#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(k);
    for (auto& x : a) {
        std::cin >> x;
        x = n - x;
    }
    sort(a.begin(), a.end());
    unsigned long long acc = 0;
    int i = 0;
    for (; i < k; i++) {
        acc += a[i];
        if (acc >= n) break;
    }
    std::cout << i << '\n';
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
}
