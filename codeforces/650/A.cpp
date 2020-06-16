#include <bits/stdc++.h>

using namespace std;

void solve() {
    std::string b;
    std::cin >> b;
    for (size_t i = 0; i < b.length(); i += 2)
        std::cout << b[i];
    std::cout << b.back() << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
