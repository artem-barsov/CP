#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll a, b;
    std::cin >> a >> b;
    ll ans1 = llabs(a-b);
    if (ans1) {
        ll ans2 = min({a%ans1, ans1-(a%ans1), b%ans1, ans1-(b%ans1)});
        std::cout << ans1 << ' ' << ans2 << '\n';
    }
    else
        std::cout << "0 0" << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
