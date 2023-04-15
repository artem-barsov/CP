#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

using Graph = vector<vector<int>>;

// void solve(int n, int k) {
void solve() {
    int n, k;
    cin >> n >> k;
    // cout << "==========================\n";
    // cout << "n = " << n << ", k = " << k << endl;

    if (n == k) {
        cout << -1 << endl;
        return;
    }

    if (n == 4 && k == 0) {
        cout << "4\n1 2\n2 3\n3 4\n4 1\n";
        return;
    }

    if (n == 5 && k == 0) {
        cout << "5\n1 2\n2 3\n3 4\n4 5\n5 1\n";
        return;
    }

    int m = n - k;
    if (m == 1) {
        cout << n - 1 << endl;
        for (int i = 1; i <= n - 1; i++) {
            cout << i << ' ' << n << endl;
        }
    } else if (m == 2) {
        cout << -1 << endl;
    } else if (k == 0 && n > 5 && n < 7) {
        cout << n - 1 + (n - 1) / 2 << endl;

        for (int i = 1; i <= n - 2; i++) {
            cout << i << ' ' << i + 1 << endl;
        }

        for (int i = 1; i <= n - 1; i += 2) {
            cout << i << ' ' << n << endl;
        }
    } else {
        cout << k + m - 1 + (m) / 2 << endl;

        for (int i = 1; i <= k; i++) {
            cout << i << ' ' << k + 1 << endl;
        }

        for (int i = k + 2; i <= n; i++) {
            cout << i << ' ' << k + 1 << endl;
        }

        for (int i = n; i > k + 2; i -= 2) {
            cout << i << ' ' << i - 1 << endl;
        }

        if ((m - 1) & 1) {
            cout << k + 2 << ' ' << n << endl;
        }
    }
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--)
        solve();

    // for (int i = 3; i <= 50; i++)
    //     for (int j = 0; j <= i; j++)
    //         solve(i, j);

    return 0;
}
