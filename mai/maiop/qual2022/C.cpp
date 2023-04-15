#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

struct Dom { int x, h; };

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n;
    cin >> n;
    vector<Dom> a(n);
    for (auto&& [x, h] : a) cin >> x >> h;
    int max_cnt = 1, cnt = 1, rx = a[0].x + a[0].h;
    for (int i = 1; i < n; i++) {
        if (a[i].x < rx) cnt++;
        else {
            max_cnt = max(max_cnt, cnt);
            cnt = 1;
        }
        rx = max(rx, a[i].x + a[i].h);
    }
    max_cnt = max(max_cnt, cnt);
    reverse(a.begin(), a.end());
    int t = a[0].x;
    for (auto &[x, h] : a) x = t - x;
    cnt = 1, rx = a[0].x + a[0].h;    
    for (int i = 1; i < n; i++) {
        if (a[i].x < rx) cnt++;
        else {
            max_cnt = max(max_cnt, cnt);
            cnt = 1;
        }
        rx = max(rx, a[i].x + a[i].h);
    }
    max_cnt = max(max_cnt, cnt);
    cout << max_cnt << '\n';
}