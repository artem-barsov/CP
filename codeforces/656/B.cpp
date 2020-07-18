#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> p(n+1);
    for (int i = 0; i < 2*n; i++) {
        int a;
        std::cin >> a;
        if (p[a]) continue;
        std::cout << a << ' ';
        p[a] = true;
    }
    std::cout << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
