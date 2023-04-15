#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> d(n), a(n);
    for (auto&& x : d) cin >> x;
    a[0] = d[0];
    for (int i = 1; i < n; i++) {
        if (a[i-1] - d[i] >= 0 && d[i] != 0) {
            cout << -1 << '\n';
            return;
        }
        a[i] = a[i-1] + d[i];
    }
    for (auto &&x : a) cout << x << ' ';
    cout << '\n';
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    cin >> t;
    while (t--) solve();
}