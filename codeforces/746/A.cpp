#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

void solve() {
    int n, h;
    std::cin >> n >> h;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    sort(a.begin(), a.end());
    int d = a[n-2] + a[n-1];
    int t = ceil(h*1.0 / d);
    if (t * d - a[n-2] >= h)
        std::cout << 2*t - 1 << '\n';
    else
        std::cout << 2*t << '\n';
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) solve();
}
