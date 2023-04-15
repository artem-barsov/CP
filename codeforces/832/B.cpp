#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int n;
    cin >> n;
    int l = 2, r = 3*n;
    queue<pair<int, int>> qout;
    while (l < r) {
        qout.emplace(l, r);
        l += 3;
        r -= 3;
    }
    cout << qout.size() << '\n';
    while (!qout.empty()) {
        cout << qout.front().first << ' ' << qout.front().second << '\n';
        qout.pop();
    }
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