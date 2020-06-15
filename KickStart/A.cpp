#include <bits/stdc++.h>

using namespace std;

int solve() {
    int n;
    std::cin >> n;
    int a, b, c, res = 0;
    std::cin >> a >> b;
    for (int i = 2; i < n; i++) {
        std::cin >> c;
        if ((a < b) && (b > c)) res++;
        a = b;
        b = c;
    }
    return res;
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; i++)
        printf("Case #%d: %d\n", i, solve());
}
