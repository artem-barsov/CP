#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

// int t = 0;

// template <typename T>
// istream& operator>>(istream& is, vector<T>& v) {
//     for (auto &&x : v) is >> x;
//     return is;
// }
// template <typename T>
// ostream& operator<<(ostream& os, const vector<T>& v) {
//     for (auto &&x : v) os << x << ' ';
//     return os;
// }

void solve() {
// printf("Testcase #%d:\n", ++t);
    int n, k;
    cin >> n >> k;
    vector<ll> ps(n, numeric_limits<ll>::min());
    for (int i = n-k; i < n; i++) cin >> ps[i];
// printf("n = %d, k = %d, [ps] : ", n, k);
// cout << ps << '\n';
    vector<ll> a(n + 1);
    a.back() = numeric_limits<ll>::max();
    for (int i = n-1; i > n-k; i--) {
        a[i] = ps[i] - ps[i-1];
    }
    for (int i = n-k; i > 0; i--) {
        a[i] = a[i+1];
        ps[i-1] = ps[i] - a[i];
    }
    a[0] = ps[0];
// cout << "[ps] : " << ps << '\n';
// cout << "[a]  : " << a << '\n';
    for (int i = 1; i < n; i++) {
        if (a[i-1] > a[i]) {
            cout << "No" << '\n';
            return;
        }
    }
    cout << "Yes" << '\n';
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