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
    int eq = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i+1]) eq++;
    }
    int x = 1e9+1, cnt = 0;
    for (int i = 1; i < n - 1 && eq > 1; i++) {
        if (a[i-1] == a[i]) {
            if (a[i] == a[i+1])              eq--;
            if (i+2 < n && a[i+1] == a[i+2]) eq--;
            a[i] = a[i+1] = x++;
            cnt++;
        }
    }
    std::cout << cnt << '\n';
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
