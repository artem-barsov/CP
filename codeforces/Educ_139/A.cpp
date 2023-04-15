#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int n;
    cin >> n;
    int k = 1, ans = 0;
    while (true) {
        bool f = true;
        for (int i = 1; i <= 9; i++) {
            if (i*k <= n) ans++;
            else f = false;
        }
        if (!f) break;
        k *= 10;
    }
    cout << ans << '\n';
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    cin >> t;
    while (t--) solve();
}