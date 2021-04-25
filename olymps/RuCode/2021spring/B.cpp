#include <bits/stdc++.h>

int main(int argc, char const *argv[]) {
    int n, k;
    std::cin >> n >> k;
    std::vector<bool> all_digits(10, true);
    for (size_t i = 0; i < k; i++) {
        int d;
        std::cin >> d;
        all_digits[d] = false;
    }
    std::vector<int> digits;
    for (size_t i = 0; i < 10; i++) {
        if (all_digits[i]) digits.push_back(i);
    }
    int base = 10 - k;
    std::vector<int> m;
    while (n > 0) {
        m.push_back(n % base);
        n /= base;
    }
    for (int i = m.size()-1; i >= 0; i--) {
        std::cout << digits[m[i]];
    }
    std::cout << '\n';
}
