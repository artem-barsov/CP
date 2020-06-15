#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n;
    std::cin >> n;
    ll maxa;
    std::cin >> maxa;
    bool p = maxa > 0;
    ll sum = 0;
    for (ll i = 0; i < n-1; i++) {
        ll a;
        std::cin >> a;
        if (p == (a > 0)) maxa = max(maxa, a);
        else {
            sum += maxa;
            maxa = a;
        }
        p = (a > 0);
    }
    std::cout << sum + maxa << '\n';
}

int main(int argc, char const *argv[]) {
    ll t;
    std::cin >> t;
    while (t--) solve();
}
