#define _CRT_DISABLE_PERFCRIT_LOCKS
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    std::vector<int> a(n);
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (size_t i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        int mult = 1;
        for (size_t j = l; j <= r; j++) {
            mult = (mult * a[j-1]) % 1000000007;
        }
        cout << mult << '\n';
    }

}
