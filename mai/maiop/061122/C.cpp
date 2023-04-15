#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        if (d) cnt++;
    }
    cout << ((cnt&1) ? "Husband" : "Wife") << '\n';
}