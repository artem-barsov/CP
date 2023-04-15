#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

bool go(vector<string>& c, int cnt, int i) {
    const int n = c[0].length();
    for (int j = 0; j < n; j++) {
        if (c[i][j] != 'B' && cnt) {
            return false;
        }
        cnt--;
        if (c[!i][j] == 'B') {
            i = !i;
            cnt--;
        }
    }
    return !cnt;
}

void solve() {
    int n;
    vector<string> c(2);
    cin >> n >> c[0] >> c[1];
    int cnt = count(c[0].begin(), c[0].end(), 'B')
            + count(c[1].begin(), c[1].end(), 'B');
    int i = 0;
    bool ok1 = go(c, cnt, i);
    bool ok2 = go(c, cnt, !i);
    cout << (ok1||ok2 ? "YES" : "NO") << '\n';
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