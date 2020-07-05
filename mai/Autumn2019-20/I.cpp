#define _CRT_DISABLE_PERFCRIT_LOCKS
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    std::vector<double> a(n), pm(n+1, 1);
    std::vector<int> pos0, psMinus(n+1, 0);
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i]) {
            pm[i+1] = fmod(((double)pm[i] * a[i]), 1000000007);
            // psMinus[i+1] = (psMinus[i] + (a[i]<0));
        }
        else pos0.push_back(i+1);
    }
    for (size_t i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        bool has0 = false;
        for (size_t j = 0; j < pos0.size(); j++) {
            if ((pos0[j] >= l) && (pos0[j] <= r)) {
                cout << "0\n";
                has0 = true;
                break;
            }
        }
        if (!has0) {
            // cout << (((psMinus[r]-psMinus[l-1])&1) ? -1 : 1) * pm[r] / pm[l-1] << '\n';
            cout << pm[r] / pm[l-1] << '\n';
            cout << pm[r] * pow(pm[l-1], 1000000007-2) % 1000000007 << '\n';
        }
    }
}
