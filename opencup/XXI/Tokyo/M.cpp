#include <iostream>

using namespace std;
using ull = unsigned long long;

ull factorial(ull n) {
    if (n > 998244353) return 0;
    ull res = 1;
    while (n > 0) {
        res = (res * n) % 998244353;
        --n;
    }
    return res;
}

int main() {
    ull n;
    cin >> n;
    if (n == 11)
        std::cout << 644056242 << '\n';
    else if (n == 12)
        std::cout << 527656359 << '\n';
    else if (n >= 13)
        std::cout << 0 << '\n';
    else
        cout << factorial(factorial(n));
}
