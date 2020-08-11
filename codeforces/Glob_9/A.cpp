#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> b;
    int a;
    std::cin >> a;
    a = abs(a);
    b.push_back(a);
    bool stonks = true;
    for (int i = 0; i < n-1; i++) {
        std::cin >> a;
        a = abs(a);
        if (stonks) {
            if (a >= b.back())
                b.push_back(-a);
            else
                b.push_back(a);
            stonks = !stonks;
        }
        else {
            if (a <= b.back())
                b.back() = -b.back();
            b.push_back(a);
            stonks = !stonks;
        }
    }
    for (int i = 0; i < n; i++)
        std::cout << b[i] << ' ';
    std::cout << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
