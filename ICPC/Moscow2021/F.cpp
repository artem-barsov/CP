#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n < 4) {
        cout << -1 << endl;
    } else {
        cout << n + 1 << endl;
        for (int i = 2; i <= n; i++) {
            cout << i - 1 << ' ' << i << endl;
        }
        cout << 1 << ' ' << n << endl;
        cout << 1 << ' ' << n - 1 << endl;
    }
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
        solve();
}
