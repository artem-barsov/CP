#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long a, b, r;
    cin >> a >> b >> r;

    if (r >= a && r <= b) {cout << r << ' ' << b + 1 << endl; return;}
    else if (r <= b) {
        long long mod = max(a - r, r + 1);
        if (mod + r >= a && mod + r <= b) {
            cout << mod + r << ' ' << mod << endl;
            return;
        }
    }
    cout << "-1 -1\n";
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    signed t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
