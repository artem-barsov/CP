#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    ll a, b;
    cin >> a >> b;
    ll num = a, den = 1ll << b;
    string ans;
    while (den > 1) {
        // cout << num << ' ' << den << '\n';
        if (num <= den / 2) {
            ans += '0';
            den /= 2;
        }
        else {
            ans += '1';
            num = den - num;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}