#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n, m, q;
    cin >> n >> m >> q;
    while (q--) {
        int t;
        cin >> t;
        int x = 0, y = 0;
        int L = t / (m + 1);
        if ((L < n / 2) || (L == n / 2) && (t % (m + 1) == 0)) {
            x = 2 * L;
            y = ((L&1) ? m-1 : 0);
            int rem = t % (m + 1);
            if (rem == m) x++;
            if (y == 0) y += min(m-1, rem);
            else        y -= min(m-1, rem);
        }
        else if (L == n/2 && L*(m+1) < t && t < L*(m+1)+m) {
            x = n - 1;
            if (L&1) y = m - (t-L*(m+1)) - 1;
            else y = t - L*(m+1);
        }
        else if (L == n/2 && t == L*(m+1)+m) {
            x = n - 1;
            y = ((L&1) ? 0 : m-1);
        }
        else if (L == n/2+1 && (t == (L-1)*(m+1)+m+1 || t == (L-1)*(m+1)+m+2)) {
            x = n - 2;
            y = (((L-1)&1) ? 0 : m-1);
        }
        else {
            L = (t - 1) / (m + 1) - (n / 2) - 1;
            x = n-2 - 2*L;
            int rem = (t-((n/2)*(m+1)+m+2)) % (m + 1);
            if (rem == m) x--;
            if ((L&1) ^ ((n/2)&1)) y = 0 + min(m-1, rem);
            else y = m-1 - min(m-1, rem);
        }
        cout << x << ' ' << y << '\n';
    }
}