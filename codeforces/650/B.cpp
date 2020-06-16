#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, wrong_odd_pos = 0, wrong_even_pos = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        if ((i&1) && !(a&1))
            wrong_odd_pos++;
        else if (!(i&1) && (a&1))
            wrong_even_pos++;
    }
    if (wrong_odd_pos == wrong_even_pos)
        std::cout << wrong_even_pos << '\n';
    else
        std::cout << -1 << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
