#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull solve() {
    ull n, d;
    std::cin >> n >> d;
    std::vector<ull> x(n);
    for (int i = 0; i < n; i++) std::cin >> x[i];
    for (int i = n-1; i >= 0; i--) d = (d / x[i]) * x[i];
    return d;
}

int main(int argc, char const *argv[]) {
    ull t;
    std::cin >> t;
    for (ull i = 1; i <= t; i++)
        std::cout << "Case #" << i << ": " << solve() << '\n';
}
