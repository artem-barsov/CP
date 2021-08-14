#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    if (n <= 125)
        std::cout << 4 << '\n';
    else if (n <= 211)
        std::cout << 6 << '\n';
    else
        std::cout << 8 << '\n';
}
