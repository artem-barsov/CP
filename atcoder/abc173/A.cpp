#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    std::cout << 1000 - (n % 1000 ? n % 1000 : 1000) << '\n';
}
