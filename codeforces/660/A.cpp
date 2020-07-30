#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    if (n > 30) {
        if (n == 36) printf("YES\n5 6 10 15\n");
        else if (n == 40) printf("YES\n1 10 14 15\n");
        else if (n == 44) printf("YES\n6 7 10 21\n");
        else printf("YES\n6 10 14 %d\n", n-30);
    }
    else
        std::cout << "NO" << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
