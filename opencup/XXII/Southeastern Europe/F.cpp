#include <bits/stdc++.h>
#define int long long

using namespace std;

struct po { int i, v; };

void solve() {
    int n, x, r, p, k;
    cin >> n >> x >> r >> p >> k;
    string s;
    cin >> s;
    vector<po> dep(n);
    for (int i = 0; i < n; i++) {
        dep[i].i = i;
        dep[i].v = p * (n - i);
        if (s[i] == '1') {
            dep[i].v += r * (n - i);
        }
    }
    sort(dep.begin(), dep.end(), [](po l, po r) {return l.v > r.v;});
    string ps = s;
    for (int i = 0; i < n; i++) {
        if (i < k) {
            ps[dep[i].i] = '1';
        } else {
            ps[dep[i].i] = '0';
        }
    }
    int pstack = 0, rstack = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1')
            rstack++;
        if (ps[i] == '1') {
            pstack++;
            if (rstack > 0)
                rstack--;
        }
        ans += x + p * pstack - r * rstack;
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
        solve();
}
