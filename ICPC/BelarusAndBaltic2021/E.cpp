#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int zeros = 0;
    int pos = 0, neg = 0;
    int minn = INT_MAX;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x == 0)
            zeros++;
        else if (x < 0)
            neg++;
        else
            pos++;

        minn = min(minn, abs(x));
    }


    if (neg & 1) {
        if (zeros > 0) {
            cout << zeros << endl;
        } else {
            cout << zeros + minn + 1 << endl;
        }
    } else {
        cout << zeros << endl;
    }

}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
