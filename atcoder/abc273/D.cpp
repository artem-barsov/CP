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
    int h, w, r, c, n;
    cin >> h >> w >> r >> c >> n;
    map<int, set<int>> walls_in_r, walls_in_c;
    for (int i = 0; i < n; i++) {
        int ri, ci;
        cin >> ri >> ci;
        walls_in_r[ri].insert(ci);
        walls_in_c[ci].insert(ri);
    }
    int q;
    cin >> q;
    while (q--) {
        char d; int l;
        cin >> d >> l;
        if (d == 'R') {
            int lim = w + 1;
            if (walls_in_r.count(r)) {
                auto it = walls_in_r[r].lower_bound(c);
                if (it != walls_in_r[r].end())
                    lim = *it;
            }
            c = min(c+l, lim-1);
        }
        else if (d == 'L') {
            int lim = 0;
            if (walls_in_r.count(r)) {
                auto it = walls_in_r[r].lower_bound(c);
                if (it != walls_in_r[r].begin())
                    lim = *prev(it);
            }
            c = max(c-l, lim+1);
        }
        else if (d == 'D') {
            int lim = h + 1;
            if (walls_in_c.count(c)) {
                auto it = walls_in_c[c].lower_bound(r);
                if (it != walls_in_c[c].end())
                    lim = *it;
            }
            r = min(r+l, lim-1);
        }
        else if (d == 'U') {
            int lim = 0;
            if (walls_in_c.count(c)) {
                auto it = walls_in_c[c].lower_bound(r);
                if (it != walls_in_c[c].begin())
                    lim = *prev(it);
            }
            r = max(r-l, lim+1);
        }
        cout << r << ' ' << c << '\n';
    }
}
