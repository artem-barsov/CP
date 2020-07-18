#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x[3];
    std::cin >> x[0] >> x[1] >> x[2];
    sort(x, x+3);
    if (x[1] == x[2]) {
        printf("YES\n%d %d %d\n", x[2], x[0], 1);
    }
    else
        std::cout << "NO" << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
