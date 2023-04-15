#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n;
    std::cin >> n;
    std::vector<ll> a(n);
    for (auto& x : a) std::cin >> x;
    sort(a.begin(), a.end());
    std::vector<int> cnt(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        cnt[i] = i+1 - (upper_bound(a.begin(), a.begin()+i+1, sum,
            [i](const ll& el, const ll& ai) { return el < ai * (i+1); })
        - a.begin());
    }
    std::cout << *max_element(cnt.begin(), cnt.end()) << '\n';
}
