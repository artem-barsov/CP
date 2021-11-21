#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int m = n - k - 1;
    int need = k / 3;
    cout << k / 4 << ' ';
    if (need <= m) cout << "0\n";
    else {
        cout << (k - m * 3) / 4 << endl;
    }
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
        solve();
}
