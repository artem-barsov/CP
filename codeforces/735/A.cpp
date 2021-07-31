#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    std::vector<unsigned long long> a(n);
    for (auto& x : a) std::cin >> x;
    a.push_back(0);
    unsigned long long ans = a[0] * a[1];
    for (int i = 1; i < a.size()-1; i++) {
        if (a[i-1] <= a[i] && a[i] > a[i+1]) {
            ans = max({ans, a[i-1]*a[i], a[i]*a[i+1]});
        }
    }
    std::cout << ans << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
