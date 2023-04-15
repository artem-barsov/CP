#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    if (n == 2) {
        cout << abs(a[0] - a[1]) << '\n';
        return;
    }

     // max to rmost
    int maxel = *max_element(a.begin()+1, a.end());
    int ans1 = maxel - a[0];

     // max diff a[i] a[i+1]
    int maxdif = -INT_MAX;
    for (int i = 0; i < n-1; i++)
    {
        maxdif = max(maxdif, a[i] - a[i+1]);
    }
    int ans2 = maxdif;

    // min to lmost
    int minel = *min_element(a.begin(), a.end()-1);
    int ans3 = a.back() - minel;

    cout << max({ans1, ans2, ans3}) << '\n';
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