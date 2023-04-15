#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int x1, y1;
    cin >> x1 >> y1;
    int x2, y2;
    cin >> x2 >> y2;
    int x3, y3;
    cin >> x3 >> y3;

    int ax = x1 - x2;
    int ay = y1 - y2;
    int bx = x2 - x3;
    int by = y2 - y3;
    int cx = x1 - x3;
    int cy = y1 - y3;

    int cnt = 0;
    cnt += (!ax || !ay);
    cnt += (!bx || !by);
    cnt += (!cx || !cy);
    cout << (cnt != 2 ? "YES" : "NO") << '\n';
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