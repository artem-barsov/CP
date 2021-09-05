#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int k, a, b;
    std::cin >> k >> a >> b;
    if ((!a && !b) || (b == -a))
        std::cout << 1 << '\n';
    else
        std::cout << k + 1 << '\n';
}
