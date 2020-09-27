#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull lcm(ull a, ull b) {
    return a * b / __gcd(a, b);
}

int main(int argc, char const *argv[]) {
    ull n;
    std::cin >> n;
    std::vector<ull> a(n-1);
    for (ull i = 0; i < n-1; i++) std::cin >> a[i];
    std::vector<ull> b(n-1);
    b[0] = a[0];
    for (ull i = 1; i < n-1; i++) {
        b[i] = lcm(a[i-1], a[i]);
        if (a[i-1] != __gcd(b[i-1], b[i])) {
            std::cout << -1 << '\n';
            return 0;
        }
    }
    b.push_back(a.back());
    for (ull i = 0; i < b.size(); i++) {
        std::cout << b[i] << ' ';
    }
    std::cout << '\n';
}
