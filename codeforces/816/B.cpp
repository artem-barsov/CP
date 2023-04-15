#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

void solve() {
    ll n, k, b, s;
    cin >> n >> k >> b >> s;
    if ((n-1)*(k-1) >= s-min(s, (k*(b+1)-1)) && min(s, (k*(b+1)-1))/k==b) {
        vector<ll> a;
        a.push_back(min(s, (k*(b+1)-1)));
        ll ost = s - a.back();
        for (int i = 0; i < n-1; i++)
        {
            if (k-1 <= ost) {
                a.push_back(k-1);
                ost -= k-1;
            }
            else {
                a.push_back(ost);
                ost = 0;
            }
        }
        for (int i = n-1; i >= 0; i--)
        {
            cout << a[i] << ' ';
        }
        cout << '\n';
        
    }
    else cout << -1 << '\n';
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    std::cin >> t;
    while (t--) solve();
}