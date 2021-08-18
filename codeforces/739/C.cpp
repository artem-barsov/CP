#include <bits/stdc++.h>

using namespace std;

void solve() {
    int k;
    std::cin >> k;
    int l = ceil(sqrt(k));
    if ((l-1)*(l-1) < k&&k < l*l-l+1)
        std::cout << k - (l-1)*(l-1) << ' ' << l << '\n';
    else
        std::cout << l << ' ' << l*l - k + 1 << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
