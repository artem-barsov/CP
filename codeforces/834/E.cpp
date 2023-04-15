#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

int f(priority_queue<ll, vector<ll>, greater<>> pq, ll h, int drink[3]) {
    while (!pq.empty() && pq.top() < h) {
        h += pq.top() / 2;
        pq.pop();
    }
    h *= drink[0];
    while (!pq.empty() && pq.top() < h) {
        h += pq.top() / 2;
        pq.pop();
    }
    h *= drink[1];
    while (!pq.empty() && pq.top() < h) {
        h += pq.top() / 2;
        pq.pop();
    }
    h *= drink[2];
    while (!pq.empty() && pq.top() < h) {
        h += pq.top() / 2;
        pq.pop();
    }
    return pq.size();
}

void solve() {
    ll n, h;
    cin >> n >> h;
    priority_queue<ll, vector<ll>, greater<>> pq;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        pq.push(a);
    }
    int ans = min({
        f(pq, h, new int[3]{2,2,3}),
        f(pq, h, new int[3]{2,3,2}),
        f(pq, h, new int[3]{3,2,2}),
    });
    cout << n - ans << '\n';
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    cin >> t;
    while (t--) solve();
}