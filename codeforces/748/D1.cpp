#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    bool all_same = true;
    for (int i = 0; i < n; i++) {
        if (a[i] != a[0]) {
            all_same = false;
            break;
        }
    }
    if (all_same) {
        std::cout << -1 << '\n';
        return;
    }
    int minel = *min_element(a.begin(), a.end());
    for (auto& x : a) x -= minel;
    int ans = gcd(a[0], a[1]);
    for (int i = 2; i < n; i++)
        ans = gcd(ans, a[i]);
    std::cout << ans << '\n';
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
