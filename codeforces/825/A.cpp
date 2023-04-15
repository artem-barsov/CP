#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto&& x : a) cin >> x;
    for (auto&& x : b) cin >> x;
    int x1 = 0, x2 = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1 && b[i] == 0) x1++;
        if (a[i] == 0 && b[i] == 1) x2++;
        ans += a[i] - b[i];
    }
    cout << abs(ans) + (x1 && x2) << '\n';
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