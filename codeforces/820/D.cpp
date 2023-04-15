#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (auto&& el : x) cin >> el;
    for (auto&& el : y) cin >> el;
    vector<int> poss, negs;
    for (int i = 0; i < n; i++) {
        if (y[i] - x[i] >= 0)
            poss.push_back(y[i] - x[i]);
        else
            negs.push_back(y[i] - x[i]);
    }
    sort(poss.begin(), poss.end(), std::greater<int>());
    sort(negs.begin(), negs.end(), std::less<int>());
    int cnt = 0;
    bool f = true;
    while (f) {
        f = false;
        if (!poss.empty() && !negs.empty() && poss.back() + negs.back() >= 0) {
            cnt++;
            poss.pop_back();
            negs.pop_back();
            f = true;
        }
        else if (poss.size() >= 2) {
            cnt++;
            poss.pop_back();
            poss.pop_back();
            f = true;
        }
    }
    cout << cnt << '\n';
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