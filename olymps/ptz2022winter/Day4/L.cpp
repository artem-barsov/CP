#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n;
    std::cin >> n;
    if (n == 2) {
        long long ans, _;
        std::cin >> _ >> ans;
        std::cin >> _ >> _;
        std::cout << abs(ans) << '\n';
        return 0;
    }
    std::vector<long long> sums(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long c;
            std::cin >> c;
            sums[i] += c;
        }
    }
    sort(sums.begin(), sums.end());
    long long ans = 0;
    for (int i = 0; i < n / 2; i++) ans -= sums[i];
    for (int i = n / 2; i < n; i++) ans += sums[i];
    std::cout << abs(ans) / 2ll << '\n';
}
