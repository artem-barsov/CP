#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    std::cout << (n&1 ? 0 : ((n>>1)&1 ? 1 : 2)) << '\n';
}
