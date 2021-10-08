#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

void solve() {
    long long n;
    std::cin >> n;
    if (n > 0)
        std::cout << -n + 1 << ' ' << n << '\n';
    else if (n < 0)
        std::cout << n << ' ' << -n - 1 << '\n';
    else
        std::cout << "-1 1" << '\n';
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) solve();
}
