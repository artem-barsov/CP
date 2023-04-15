#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

int height(vector<int>& a, int pos) {
    int ret = 0;
    int l = 1, r = 1;
    while (pos-l >= 0 && pos+r < a.size() &&
            a[pos-l] < a[pos-l+1] && a[pos+r-1] > a[pos+r]) {
        l++;
        r++;
    }
    return min(l, r) - 1;
}

int depth(vector<int>& a, int pos) {
    int ret = 0;
    int l = 1, r = 1;
    while (pos-l >= 0 && pos+r < a.size() &&
            a[pos-l] > a[pos-l+1] && a[pos+r-1] < a[pos+r]) {
        l++;
        r++;
    }
    return min(l, r) - 1;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto&& x : a) cin >> x;
    int hmax = 0;
    for (int i = 1; i < n-1; i++) {
        if (a[i-1] < a[i] && a[i] > a[i+1]) {
            int h = height(a, i);
            hmax = max(hmax, h);
            i += h;
        }
    }
    int dmax = 0;
    for (int i = 1; i < n-1; i++) {
        if (a[i-1] > a[i] && a[i] < a[i+1]) {
            int h = depth(a, i);
            dmax = max(dmax, h);
            i += h;
        }
    }
    cout << hmax << ' ' << dmax << '\n';
}

int main() {
    freopen("dales.in", "r", stdin);
    freopen("dales.out", "w", stdout);
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    cin >> t;
    while (t--) solve();
}