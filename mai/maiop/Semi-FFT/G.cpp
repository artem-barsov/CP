#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    int t, n, x, y;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cin >> n >> x >> y;
        int w = n / 2;
        if (w > y) {
            std::cout << "NO\n";
            continue;
        }
        int b = n - w;
        if (b > x) {
            std::cout << "NO\n";
            continue;
        }
        std::cout << "YES\n";
    }
}
