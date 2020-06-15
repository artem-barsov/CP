#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, a, b, c, d;
    std::cin >> n >> a >> b >> c >> d;
    if ((n*(a+b) < c-d) || (n*(a-b) > c+d))
        std::cout << "No" << '\n';
    else
        std::cout << "Yes" << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
