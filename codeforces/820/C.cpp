#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

struct SI {
    char c;
    int idx;
};

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<SI> a(n);
    for (int i = 0; i < n; i++)
        a[i] = { s[i], i+1 };
    if (s[0] <= s.back())
        sort(a.begin(), a.end(), [&](const SI& lhs, const SI& rhs) {
            if (lhs.c != rhs.c)               return lhs.c < rhs.c;
            if (lhs.idx == 1 || rhs.idx == n) return true;
            if (rhs.idx == 1 || lhs.idx == n) return false;
            return lhs.idx < rhs.idx;
        });
    else
        sort(a.begin(), a.end(), [&](const SI& lhs, const SI& rhs) {
            if (lhs.c != rhs.c)               return lhs.c > rhs.c;
            if (lhs.idx == 1 || rhs.idx == n) return true;
            if (rhs.idx == 1 || lhs.idx == n) return false;
            return lhs.idx > rhs.idx;
        });
    int i = 0;
    while (a[i].idx != 1) i++;
    vector<int> vout;
    for (; a[i].idx != n; i++)
        vout.push_back(a[i].idx);
    vout.push_back(n);
    cout << abs(s[0] - s.back()) << ' ' << vout.size() << '\n';
    for (auto &&x : vout) cout << x << ' ';
    cout << '\n';
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    cin >> t;
    while (t--) solve();
}