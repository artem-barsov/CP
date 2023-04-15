#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned ll
#define endl '\n'

using namespace std;

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        char op, r;
        cin >> a >> op >> b >> r >> c;

        int res;
        if (op == '+') res = a + b;
        if (op == '-') res = a - b;
        if (op == '*') res = a * b;

        if (res == c)
            cout << "correct\n";
        else {
            cout << "incorrect\n";
            cout << a << ' ' << op << ' ' << b << " = " << res << endl;
        }
    }
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // signed t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}