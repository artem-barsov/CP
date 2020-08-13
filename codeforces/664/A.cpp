#include <bits/stdc++.h>

using namespace std;

void solve() {
    int r, g, b, w;
    std::cin >> r >> g >> b >> w;
    if ((r+g+b+w)&1) {
        if (((r&1) + (g&1) + (b&1) + (w&1) == 3) && (!r || !g || !b || !b))
            std::cout << "No" << '\n';
        else
            std::cout << "Yes" << '\n';
    }
    else {
        if (((r&1) + (g&1) + (b&1) + (w&1) == 2) || ((r&1) + (g&1) + (b&1) + (w&1) == 4)&&((!r || !g || !b || !b)))
            std::cout << "No" << '\n';
        else
            std::cout << "Yes" << '\n';
    }
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
