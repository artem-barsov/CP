#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    int sum = 0;
    for (size_t i = 0; i < n; i++) {
        int w;
        std::cin >> w;
        sum += w;
    }
    std::cout << (sum%3 ? "no" : "yes") << '\n';
}
