#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

ll calc(vector<ll>& a, vector<ll>& b) {
    vector<ll> ps_a(a.size());
    vector<ll> ps_b(b.size());
    inclusive_scan(a.begin(), a.end(), ps_a.begin());
    inclusive_scan(b.begin(), b.end(), ps_b.begin());
    if (a.size() == 0) return ps_b.back();
    if (b.size() == 0) return ps_a.back();
    ll ret = ps_a.back() + ps_b.back();
    if (a.size() > b.size()) {
        ret += ps_a[b.size()-1];
        ret += ps_b.back();
    }
    else {
        ret += ps_a.back();
        if (a.size() > 1)
            ret += ps_b[a.size()-2];
    }
    return ret;
}

void solve() {
    int n;
    cin >> n;
    vector<int> type(n);
    vector<ll> fire, cold;
    for (auto&& x : type) cin >> x;
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        if (type[i]) cold.push_back(b);
        else fire.push_back(b);
    }
    sort(fire.begin(), fire.end(), greater<ll>());
    sort(cold.begin(), cold.end(), greater<ll>());
    ll ans1 = calc(fire, cold);
    ll ans2 = calc(cold, fire);
    cout << max(ans1, ans2) << '\n';
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