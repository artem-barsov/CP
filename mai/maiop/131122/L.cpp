#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (auto &&x : v) os << x << ' ';
    return os;
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto&& x : a) cin >> x;
    for (auto&& x : b) cin >> x;
    vector<ll> sa, sb;
    for (size_t bf = 1; bf < (1ull << n); bf++) {
        bitset<17> bs(bf);
        ll s = 0;
        for (int i = 0; i < n; i++)
            if (bs[i]) s += a[i];
        sa.push_back(s);
    }
    for (size_t bf = 1; bf < (1ull << m); bf++) {
        bitset<17> bs(bf);
        ll s = 0;
        for (int i = 0; i < m; i++)
            if (bs[i]) s += b[i];
        sb.push_back(s);
    }
    int ans = 0;
    for (auto sai : sa)
        for (auto sbi : sb)
            if (sai == sbi) ans++;
    cout << ans << '\n';
}