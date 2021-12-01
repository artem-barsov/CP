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
    sort(a.begin(), a.end());
    for (int i = 0; i < n / 2; i++) {
        std::cout << a[n - i - 1] << ' ' << a[0] << '\n';
    }
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
