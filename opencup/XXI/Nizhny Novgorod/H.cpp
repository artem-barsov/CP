#include <iostream>
#include <cmath>
#include <set>

int main() {
    unsigned int n;
    std::cin >> n;
    std::set<unsigned> bad;
    bad.insert({ 1, 2, 4, 5, 6 });
    if (bad.find(n) != bad.end()) {
        std::cout << -1 << '\n';
        return 0;
    }
    if (n == 3) {
        std::cout << 4 << '\n';
        return 0;
    }
    n -= 3;
    unsigned u = ceil(std::sqrt(n));
    unsigned mm = ~0;
    for (unsigned i = 1; i <= u; ++i) {
        unsigned h = n % i;
        unsigned g = n / i;
        if (h == 0 && i < mm && i > 3) mm = i;
        if (h == 0 && g < mm && g > 3) mm = g;
    }
    std::cout << ((mm != ~0) ? mm : -1) << '\n';
}
