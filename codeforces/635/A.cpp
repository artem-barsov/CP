#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a[4];
    for (size_t i = 0; i < 4; i++) {
        std::cin >> a[i];
    }
    printf("%d %d %d\n", a[1], a[2], a[2]);
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
