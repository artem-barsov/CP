#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    bool anotb = true;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            anotb = false;
            break;
        }
    }
    if (a != b && !anotb) {
        cout << "NO" << '\n';
        return;
    }
    vector<pair<int, int>> vout;
    if (anotb) vout.emplace_back(1, n);
    int t = 0;
    if (b[0] == '1') {
        t = b.find_first_of('0');
        if (t == string::npos) {
            vout.emplace_back(1, 1);
            vout.emplace_back(2, n);
            t = n;
        }
        else {
            vout.emplace_back(1, n);
            vout.emplace_back(t+1, n);
        }
    }
    for (int i = t; i < n; i++) {
        if (b[i] == '0') continue;
        t = i;
        while (i < n && b[i] == '1') i++;
        vout.emplace_back(1, i);
        vout.emplace_back(1, t);
    }
    cout << "YES" << '\n';
    cout << vout.size() << '\n';
    for (auto &&[l, r] : vout)
        cout << l << ' ' << r << '\n';
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