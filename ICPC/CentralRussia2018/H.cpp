#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

using ll = long long;
using ull = unsigned long long;
#define int long long

using Graph = vector<vector<int>>;

void print_ans(const string& s, int n) {
    cout << n << '\n';
    for (int i = 0; i < n; ++i) {
        int j;
        cin >> j;

        cout << s[j] << ' ';
    }
    cout << '\n';
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int k, n;
    cin >> k >> n;

    if (k == 1) {
        cout << "0" << endl;
        return 0;
    }
    if (k == 2) {
        cout << "0" << endl;
        return 0;
    }
    if (k == 3) {
        cout << "0" << endl;
        return 0;
    }
    if (k == 4) {
        auto ans = "1210";
        print_ans(ans, n);
        return 0;
    }
    if (k == 5) {
        auto ans = "21200";
        print_ans(ans, n);
        return 0;
    }
    if (k == 6) {
        cout << "0" << endl;
        return 0;
    }

    cout << n << '\n';
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        if (x == 0) {
            cout << k - 4 << ' ';
        } else if (x == 1) {
            cout << 2 << ' ';
        } else if (x == 2) {
            cout << 1 << ' ';
        } else if (x == k - 4) {
            cout << 1 << ' ';
        } else {
            cout << 0 << ' ';
        }
    }

    return 0;
}
