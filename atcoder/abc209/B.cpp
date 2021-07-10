#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, x;
    std::cin >> n >> x;
    for (size_t i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        x -= a - (i&1);
    }
    std::cout << (x >= 0 ? "Yes" : "No") << '\n';
}
