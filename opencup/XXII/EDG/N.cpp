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
    unsigned long long x, y;
    std::cin >> x >> y;
    for (int i = 0; i < n - 1; i++) {
        unsigned long long a, b;
        std::cin >> a >> b;
        x = lcm(x, a);
        y = gcd(y, b);
    }
    std::cout << x / gcd(x, y) << ' ' << y / gcd(x, y) << '\n';
}
