#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

int cnt_of_2(ll x) {
    int ret = 0;
    ll t2 = 2;
    while (x % t2 == 0) {
        ret++;
        t2 <<= 1ll;
    }
    return ret;
}

void solve() {
    int n;
    cin >> n;
    int cnt2 = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt2 += cnt_of_2(a);
    }
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++) {
        pq.push(cnt_of_2(i));
    }
    int ans = 0;
    while (cnt2 < n && !pq.empty()) {
        cnt2 += pq.top();
        pq.pop();
        ans++;
    }
    cout << (cnt2 >= n ? ans : -1) << '\n';
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