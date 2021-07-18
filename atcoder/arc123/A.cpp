#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    long long a1, a2, a3;
    std::cin >> a1 >> a2 >> a3;
    long long b1 = a2 - a1;
    long long b2 = a3 - a2;
    if (b1 <= b2)
        std::cout << (b2-b1)/2 + ((b2-b1)&1)*2 << '\n';
    else
        std::cout << b1 - b2 << '\n';
}
