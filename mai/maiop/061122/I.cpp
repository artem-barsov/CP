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
    freopen("i.in", "r", stdin);
    freopen("i.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto&& x : a) cin >> x;
    int max_dist = 0;
    pair<int, int> best;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n/2; j++) {
            int l = i - j;
            if (l < 0) l = n + l;
            int r = (i + j) % n;
            if (a[l] == a[i]) {
                int d = (l < i ? i-l : i+n-l);
                if (max_dist < d) {
                    max_dist = d;
                    best = {i, l};
                }
            }
            if (a[r] == a[i]) {
                int d = (i < r ? r-i : r+n-i);
                if (max_dist < d) {
                    max_dist = d;
                    best = {i, r};
                }
            }
        }
    }
    cout << best.first+1 << ' ' << best.second+1 << '\n';
}