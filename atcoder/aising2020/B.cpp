#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    int c = 0;
    for (size_t i = 1; i <= n; i++) {
        int a;
        std::cin >> a;
        c += i&a&1;
    }
    std::cout << c << '\n';
}
