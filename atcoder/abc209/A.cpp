#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int a, b;
    std::cin >> a >> b;
    if (a <= b)
        std::cout << b-a+1 << '\n';
    else
        std::cout << 0 << '\n';
}
