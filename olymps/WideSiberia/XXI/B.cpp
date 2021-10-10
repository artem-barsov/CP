#include <bits/stdc++.h>

using namespace std;

void solve() {
    int p, q, a, b;
    std::cin >> p >> q >> a >> b;
    if ((100.0-p)*q >= (100.0-q)*a*b*p) {
        std::cout << -1 << '\n';
        return;
    }
    else {
        long double ans = (100.0*b*(p-q)) / (q*(100.0-p) + a*b*p*(q-100.0));
        std::cout << ceil(ans) << '\n';
    }
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
