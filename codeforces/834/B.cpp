#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (auto &&x : v) os << x << ' ';
    return os;
}

void solve() {
    int m, s;
    cin >> m >> s;
    set<int> b;
    for (int i = 0; i < m; i++) {
        int bi;
        cin >> bi;
        b.insert(bi);
    }
    for (int i = 1; true; i++) {
        if (b.contains(i)) continue;
        s -= i;
        b.insert(i);
        if (s < 0) {
            cout << "NO" << '\n';
            return;
        }
        if (s == 0) break;
    }
    vector<int> p(b.begin(), b.end());
    for (int i = 0; i < p.size()-1; i++) {
        if (p[i+1] - p[i] != 1) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
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