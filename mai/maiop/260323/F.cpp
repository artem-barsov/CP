#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int h, w, n;
    cin >> h >> w >> n;
    int hh = h-2, ww = w-2;
    if (((ww+1)/2)*((hh+1)/2) + (ww/2)*(hh/2) < n) {
        cout << "Impossible\n" << '\n';
        return;
    }
    cout << string(w, '.') << '\n';
    for (int i = 0; i < hh; i++) {
        cout << '.';
        for (int j = 0; j < ww; j++) {
            if (n && !((i+j)&1)) {
                cout << '#';
                n--;
            }
            else cout << '.';
        }
        cout << '.' << '\n';
    }
    if (h > 1) cout << string(w, '.') << '\n';
    cout << '\n';
}

int main() {
    freopen("figure.in", "r", stdin);
    freopen("figure.out", "w", stdout);
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    cin >> t;
    while (t--) solve();
}