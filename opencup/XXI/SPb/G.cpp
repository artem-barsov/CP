#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

int main(int argc, char const *argv[]) {
    ull n;
    std::cin >> n;
    if (n == 4) {
        std::cout << 1 << '\n';
        std::cout << "2 2" << '\n';
        return 0;
    }
    ull bound = sqrt(n);
    ull a = 2;
    bool ok = false;
    if (n&1 || (n == 2)) {
        for (a = 3; a <= bound; a+=2) {
            if (n % a == 0) {
                ok = true;
                break;
            }
        }
    }
    else ok = true;
    if (ok) {
        ull b = n/a;
        if (a != b) {
            std::cout << 3 << '\n';
            std::cout << a << ' ' << 1 << '\n';
            std::cout << b << ' ' << 1 << '\n';
            std::cout << 1 << ' ' << n - (a + b) << '\n';
        }
        else {
            std::cout << 2 << '\n';
            std::cout << a << ' ' << 2 << '\n';
            std::cout << 1 << ' ' << n - 2*a << '\n';
        }
    }
    else
        std::cout << -1 << '\n';
}
