#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    int ma = 0, mc = 0;
    for (size_t i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        if (a > ma) {
            ma = a;
            mc = 1;
        }
        else if (a == ma)
            ++mc;
    }
    std::cout << n - mc << '\n';
}
