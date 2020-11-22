#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, m;
    std::cin >> n >> m;
    unsigned long long sum = 0;
    for (size_t i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        sum += x;
    }
    std::cout << (sum % m == 0 ? "YES" : "NO") << '\n';
}
